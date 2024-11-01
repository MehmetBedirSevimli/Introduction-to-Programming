PROGRAMLAMAYA GİRİŞ DERSİ

ÖDEVİ - 1

Zaman adında bir struct oluşturun. 
Bu struct içinde **int saat**, **int dakika**, **int saniye** ve **long toplam\_saniye** tipinde dört değişken olsun. 

Klavyeden 12:59:59 formatında saat, dakika, saniye yi girerek bunları **struct Zaman** tipinde bir değişkende saklayın. 

**NOT: girilen saat,dakika,saniye değerlerinin 60'dan büyük eşit ve 0'dan küçük olup olmadığını kontrol ediniz.** 

Ana programda girilen zaman struct tipindeki değişkeni aşağıdaki formüle göre saniyeyi hesaplayarak toplam\_saniye değişkeninde saklayın. 

Toplam saniye formülü : 

long totalsecs= t1.saat\*3600+t1.dakika\*60+t1.saniye //t1 değişkeni struct zaman tipinde tanımlanmış kabul edilmiştir.

NOT: değişken isimlendirmeleri a,b,c,x,y,z,t1,t2 vs. gibi olmayacaktır.

**Yaptığınız ödevin değerlendirilebilmesi için aşağıdaki ekran çıktısının aynısını yapmış olmanız gerekiyor. Farklı şekilde işlem yapmaya çalışmayınız.**

Örnek ekran çıktısı :

Saat:Dakika:Saniye şeklinde zamanı giriniz : 12:34:05

Saniye olarak hesaplana değerler : 45245

NOT: Saniye:Dakika:Saniye şeklinde girilmeyen değerler kabul edilmeyecektir.Saati girin, dakikayı girin,saniyeyi girin diye yapmayın.

Örnek ekran çıktısı :

Saat:Dakika:Saniye şeklinde zamanı giriniz : 55:104:505

girilen saat değeri 55 yanlis girilmistir.

girilen dakika değeri 104 yanlis girilmistir.

girilen saniye değeri 505 yanlis girilmistir.

PROGRAM sonu. 

