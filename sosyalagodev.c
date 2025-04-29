#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

typedef struct Node {
    int id;
    struct Node* next;
} Node;

typedef struct {
    int id;
    Node* friends;
} User;

User users[MAX_USERS];
int user_count = 0;

int find_user_index(int id) {
    int i;
    for (i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            return i;
        }
    }
    return -1;
}

void add_friendship(int id1, int id2) {
    int i1 = find_user_index(id1);
    int i2 = find_user_index(id2);
    Node* newNode1;
    Node* newNode2;

    if (i1 == -1 || i2 == -1) return;

    newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->id = id2;
    newNode1->next = users[i1].friends;
    users[i1].friends = newNode1;

    newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->id = id1;
    newNode2->next = users[i2].friends;
    users[i2].friends = newNode2;
}

void read_dataset(const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[256];

    if (!file) {
        printf("Dosya açýlamadý!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "USER", 4) == 0) {
            int id;
            sscanf(line, "USER %d", &id);
            users[user_count].id = id;
            users[user_count].friends = NULL;
            user_count++;
        } else if (strncmp(line, "FRIEND", 6) == 0) {
            int id1, id2;
            sscanf(line, "FRIEND %d %d", &id1, &id2);
            add_friendship(id1, id2);
        }
    }

    fclose(file);
}

void dfs_internal(int index, int depth, int max_depth, int visited[]) {
    Node* f;

    if (depth > max_depth) return;
    visited[index] = 1;

    if (depth > 0) {
        printf("ID %d mesafe %d\n", users[index].id, depth);
    }

    f = users[index].friends;
    while (f != NULL) {
        int f_index = find_user_index(f->id);
        if (!visited[f_index]) {
            dfs_internal(f_index, depth + 1, max_depth, visited);
        }
        f = f->next;
    }
}

void dfs_friends(int start_id, int max_depth) {
    int visited[MAX_USERS];
    int i;
    int start_index = find_user_index(start_id);

    if (start_index == -1) {
        printf("Kullanýcý bulunamadý.\n");
        return;
    }

    for (i = 0; i < MAX_USERS; i++)
        visited[i] = 0;

    dfs_internal(start_index, 0, max_depth, visited);
}

void common_friends(int id1, int id2) {
    int i1 = find_user_index(id1);
    int i2 = find_user_index(id2);
    Node *f1, *f2;

    if (i1 == -1 || i2 == -1) {
        printf("Kullanýcýlardan biri bulunamadý.\n");
        return;
    }

    printf("Ortak arkadaslar: ");
    for (f1 = users[i1].friends; f1 != NULL; f1 = f1->next) {
        for (f2 = users[i2].friends; f2 != NULL; f2 = f2->next) {
            if (f1->id == f2->id) {
                printf("%d ", f1->id);
            }
        }
    }
    printf("\n");
}

int main() {
    read_dataset("veriseti.txt");

    printf("Kullanýcý 101'in 2 mesafe icindeki arkadaslarý:\n");
    dfs_friends(101, 2);

    printf("\nKullanýcý 101 ve 102 ortak arkadaslarý:\n");
    common_friends(101, 102);

    return 0;
}

