PROGRAMLAMAYA GİRİŞ DERSİ

ÖDEVİ - 3

1) Ogrenci sismli bir struct veri tipi oluşturunuz?
1) Yapı üye değişkenleri Adi, soyadi, No, kısa sınav1, kısa sınav2, ödev1, ödev2, proje, vize, final ve Tarih struct veri türünden doğum tarihi olsun
1) Tarih yapı üyeleri, gün, ay yıl olsun.
1) Belirleyeceğiniz 30 isim ve soy isim için iki string dizi oluşturunuz?
1) Öğrencilerin 100’lük notunu harfe çeviren bir fonksiyon yazınız?
1) Girilen notun doğruluğunu kontrol eden bir fonksiyon yazınız?

` `Girlen notu kontrol için aşağıdaki kod uyarlanabilir. 

||<p>#include <iostream></p><p>using namespace std;</p><p>float oku(string s,float min, float max);</p><p>int main()</p><p>{</p><p>`	`float notu;</p><p>`	`cout << " sayi  " << oku(" notu giriniz? ", 0.0, 100.0) << endl;</p><p>}</p><p>float oku(string s, float min, float max)</p><p>{</p><p>`	`float sayi;</p><p>`	`do</p><p>`	`{ </p><p>`		`cout << s; cin >> sayi;</p><p>`	`} while (!(sayi >= min && sayi <= max));</p><p>`	`return sayi;</p><p>}</p>|
| :- | :- |

100 öğrenciyi atayabileceğiniz, Ogrenci veri tipinden bir dizi oluşturun.

Öğrenci dizisinin elemanlarını belirlerken kullanıcıya iki seçenek sunulacaktır.

**Birinci seçenek;**

Ogrenci değişkeninin üyeleri rastgele(random) belirlenecektir. ad ve soyad dizilerinden rastgele belirlenirken, notlar rastgele atanacaktır. Her bir not değişkeni için,100 öğrenciden %10’unun notu 0-40 arasında,%50’ sinin 40 ile 70, %15’inin 70 ile 80 ve  %25’inin 80 ile 100 olsun.

Rastgele sayı üretmek için aşağıdaki kod uyarlanabilir.

||<p>#include <iostream></p><p>#include <iomanip></p><p>using namespace std;</p><p></p><p>int main()</p><p>{</p><p></p><p>`    `int c;</p><p>`    `for (int i = 1; i < 10; i++)</p><p>`    `{</p><p>`        `c = rand() % 100;</p><p>`        `cout << c << endl;</p><p>`    `}</p><p>}</p>|
| :- | :- |

**İkinci seçenek;**

**Ogrenci değişkeni üye değerleri kullanıcıdan istenecek.** Girilen notların doğruluğu foksiyon ile kontrol edilecek(0 ile 100 arasında mı? Diye).

Yıl içi hotu hesabı için

Vizenin%50+kısa sınav1%7+kısa sınav2%7+odev1%10+odev2%10+proje%16

Başarı notu hesabı için

`   `Yıl içi notunun%55+final%45

Daha sonra bir menü ile aşağıdaki işlemler gerçekleştirilsin. Her menü seçeneği için bir fonksiyon yazılsın.

1. Sınıfın listesi yazdırılsın. Yazdırmada her 20 öğrenci yazdırıldıktan sonra bekletilsin. Bir tuşa basıldıktan sonra ekran silinip sonraki 20 öğrenci yazdırılsın.
1. Sınıfın en yüksek notu hesaplansın.
1. Sınıfın en düşük notu hesaplansın.
1. Sınıfın ortalaması hesaplansın.
1. Sınıfın standart sapması hesaplansın.
1. Başarı notu belirli bir aralıkta olanlar listelensin(örneğin 50<=notu<80 gibi)
1. Başarı notu belirtilen bir değerin altında olan öğrencilerin listesi alınabilsin( örğ. Notu<70). 
1. Başarı notu belirtilen bir değerin üstünde olan öğrencilerin listesi alınabilsin( örğ. Notu>70). 


