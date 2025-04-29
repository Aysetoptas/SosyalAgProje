# Sosyal Ağ Analizi Projesi

Bu proje, sosyal ağ verilerini kullanarak kullanıcılar arasındaki arkadaşlık ilişkilerini analiz etmek için bir C programı geliştirmeyi amaçlamaktadır. Ağaç tabanlı veri yapıları ve derinlik öncelikli arama (DFS) gibi algoritmalarla, kullanıcıların ilişkilerini analiz etmek mümkündür. Ayrıca, arkadaşlık ilişkilerine göre topluluk tespiti ve ortak arkadaş analizi yapılmaktadır.

## Proje Özeti

- **Veri Yapıları**: Ağaç tabanlı veri yapıları (Linked List ve Red-Black Tree)
- **Algoritmalar**: Derinlik Öncelikli Arama (DFS), Ortak Arkadaşlar Analizi, Topluluk Tespiti
- **Dosyalar**:
  - `sosyalagodev.c`: Programın C dilinde yazılmış kaynak kodu.
  - `veriseti.txt`: Kullanıcı ve arkadaşlık ilişkileriyle ilgili verileri içeren dosya.

## Özellikler

1. **İlişki Ağacı**: Kullanıcılar arasındaki arkadaşlık ilişkilerini bir bağlantı listesi (linked list) ile modelleme.
2. **DFS (Depth-First Search)**: Belirli bir kullanıcının belirli mesafedeki arkadaşlarını bulma.
3. **Ortak Arkadaş Analizi**: İki kullanıcının ortak arkadaşlarını belirleme.
4. **Topluluk Tespiti**: Kullanıcılar arasındaki grupları analiz etme.
5. **Etki Alanı Hesaplama**: Bir kullanıcının sosyal ağ üzerindeki etkisini belirleme.

## Kullanım

1. `veriseti.txt` dosyasını kullanarak kullanıcılar ve arkadaşlık ilişkileri verisini programa yükleyin.
2. Programı çalıştırarak belirli bir kullanıcının arkadaşlık ilişkilerini analiz edin, ortak arkadaşlarını bulun veya mesafelerine göre arkadaşlarını keşfedin.

### Program Çalıştırma

- Programın çalışabilmesi için `veriseti.txt` dosyasındaki veriler doğru şekilde girilmelidir.
- Aşağıda örnek kullanım yer almaktadır:

```bash
$ gcc sosyalagodev.c -o sosyalagodev
$ ./sosyalagodev
