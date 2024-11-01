#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string timeInput;

    char colon; // ':' karakterini almak için kullanılacak

    // Zaman için yapı tanımı
    struct zaman {
        int saat;
        int dakika;
        int saniye;
        long toplam_saniye;
    };

    while (1) {

    
    cout << "Lutfen saati (HH:MM:SS formatinda) girin: ";

    cin >> timeInput;

    stringstream zamanAkisi(timeInput);

    zaman zaman1;
            
    // String'i parçalayarak zaman bilgilerini alıyoruz
    zamanAkisi >> zaman1.saat >> colon;
    zamanAkisi >> zaman1.dakika >> colon;
    zamanAkisi >> zaman1.saniye;

    // Saat, dakika ve saniyenin geçerli olup olmadığını kontrol et

    if ((zaman1.saat >= 24) || (zaman1.saat < 0)) {
        cout << "Girilen saat degeri " << zaman1.saat << " yanlis girilmistir." << endl;
        continue;
    }
    if ((zaman1.dakika >= 60) || (zaman1.dakika < 0)) {
        cout << "Girilen dakika degeri " << zaman1.dakika << " yanlis girilmistir." << endl;
        continue;
    }
    if ((zaman1.saniye >= 60) || (zaman1.saniye < 0)) {
        cout << "Girilen saniye degeri " << zaman1.saniye <<" yanlis girilmistir." << endl;
        continue;
    }

    // Eğer stringstream başarısız olmuşsa (yanlış format girilmişse)

    if (zamanAkisi.fail()) {
        cout << "Gecersiz zaman formati girdiniz!" << endl;
        continue;
    }
       
        // Eğer her şey doğruysa, toplam saniyeyi hesapla
        long toplam_saniye = zaman1.saat * 3600 + zaman1.dakika * 60 + zaman1.saniye;
        cout << "Saniye olarak hesaplanan toplam deger: " << toplam_saniye << endl;

        // Başarılı bir giriş sonrası döngüyü sonlandırabiliriz
        break;

    }

}