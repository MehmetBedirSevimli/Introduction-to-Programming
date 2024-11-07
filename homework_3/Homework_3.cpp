#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <vector> 
#include <algorithm>
#include <random>
#include <cmath> // ortalama ve standart sapma hesaplamaları için
#include <limits> // numeric_limits kullanınmı için

using namespace std;

struct Tarih {
    int gun;
    int ay;
    int yil;
};

struct Ogrenci {
    string adi;
    string soyadi;
    int no;
    float kisaSinav1;
    float kisaSinav2;
    float odev1;
    float odev2;
    float proje;
    float vize;
    float final;
    float yilIciNotu;  // Yıl içi notu
    float basariNotu;  // Başarı notu
    Tarih dogumTarihi; // Doğum tarihi için Tarih struct'ını kullanıyoruz
};

// Öğrenci bilgilerini rastgele atama fonksiyonu
Ogrenci rastgeleOgrenciAta(const string isimler[], const string soyisimler[], int ogrenciNo);

// Rastgele bir not üretmek için belirtilen aralık ve yüzdelik dilimlere göre not dağılımı yapacak fonksiyon

vector<float> notDagilimi(int toplamOgrenci);

// Notu harf derecesine çeviren fonksiyon
string notuHarfDerecesineCevir(float notYuzde);

// Notu doğrulayan fonksiyon (0 ile 100 arasında olup olmadığını kontrol eder)
float notuDogrula();

// Öğrenci bilgilerini manuel olarak alır
Ogrenci manuelOgrenciGiris(int ogrenciNo);

// Yıl içi notunu hesaplayan fonksiyon
float yilIciNotuHesapla(const Ogrenci& ogrenci);

// Başarı notunu hesaplayan fonksiyon
float basariNotuHesapla(const Ogrenci& ogrenci);

// Menü işlemleri gerçekleştiren fonksiyon prototiplerini tanımlıyoruz
void sinifListesiYazdir(const Ogrenci ogrenciler[], int ogrenciSayisi);

void sinifListesiYazdir(const Ogrenci ogrenciler[]);

float enYuksekNotHesapla(const Ogrenci ogrenciler[]);

float enDusukNotHesapla(const Ogrenci ogrenciler[]);

float snifOrtalamasiHesapla(const Ogrenci ogrenciler[]);

float sinifStandartSapmasiHesapla(const Ogrenci ogrenciler[]);

void notAraligindaOgrenciler(const Ogrenci ogrenciler[], float minNot, float maxNot);

void belirliDegerAltindaOgrenciler(const Ogrenci ogrenciler[], float maxNot);

void belirliDegerUstundeOgrenciler(const Ogrenci ogrenciler[], float minNot);

int main()
{   
    // Türkçe karakter uyumluluğunu ayarlama
    setlocale(LC_ALL, "Turkish");

   // Rastgele sayılar için zaman bazlı başlatma (tohumlama)
    srand(static_cast<unsigned int>(time(0)));

    // 100 elemanlı Ogrenci türünde bir dizi tanımlıyoruz
    Ogrenci ogrenciler[100];

    // İsim ve soyisim dizilerini tanımlıyoruz
    string isimler[30] = { "Ahmet", "Mehmet", "Ayşe", "Fatma", "Ali", "Hasan", "Hüseyin", "Emre", "Ece", "Elif",
                          "Cem", "Ceren", "Burak", "Büşra", "Deniz", "Eren", "Duygu", "Gizem", "Selin", "İsmail",
                          "Berk", "Seda", "Serkan", "Gül", "Sinem", "Tuna", "Zeynep", "Can", "Murat", "Esra" };

    string soyisimler[30] = { "Yılmaz", "Kaya", "Demir", "Çelik", "Aydın", "Şahin", "Öztürk", "Arslan", "Güneş", "Polat",
                             "Kurt", "Koç", "Bulut", "Acar", "Kara", "Özdemir", "Yalçın", "Eren", "Doğan", "Çetin",
                             "Güler", "Aksoy", "Erdoğan", "Turan", "Taş", "Şimşek", "Kılıç", "Aslan", "Bozkurt", "Korkmaz" };


    // Kullanıcıya seçim yaptırma
    int secim;
    cout << "Öğrenci bilgilerini girme yöntemini seçin: " << endl;
    cout << "1. Rastgele atama" << endl;
    cout << "2. Manuel giriş" << endl;
    cin >> secim;

    if (secim == 1) {
        // Her not türü için ayrı ayrı dağılım oluşturuyoruz
        vector<float> kisaSinav1Notlar = notDagilimi(100);
        vector<float> kisaSinav2Notlar = notDagilimi(100);
        vector<float> odev1Notlar = notDagilimi(100);
        vector<float> odev2Notlar = notDagilimi(100);
        vector<float> projeNotlar = notDagilimi(100);
        vector<float> vizeNotlar = notDagilimi(100);
        vector<float> finalNotlar = notDagilimi(100);

        // Öğrencileri rastgele dolduruyoruz
        for (int i = 0; i < 100; i++) {
            ogrenciler[i] = rastgeleOgrenciAta(isimler, soyisimler, i + 1);

            // Her not türü için ayrı dağılım vektöründen sırayla atama yapıyoruz

            ogrenciler[i].kisaSinav1 = kisaSinav1Notlar[i];
            ogrenciler[i].kisaSinav2 = kisaSinav2Notlar[i];
            ogrenciler[i].odev1 = odev1Notlar[i];
            ogrenciler[i].odev2 = odev2Notlar[i];
            ogrenciler[i].proje = projeNotlar[i];
            ogrenciler[i].vize = vizeNotlar[i];
            ogrenciler[i].final = finalNotlar[i];


            // Yıl içi notunu ve başarı notunu hesapla
            ogrenciler[i].yilIciNotu = yilIciNotuHesapla(ogrenciler[i]);
            ogrenciler[i].basariNotu = basariNotuHesapla(ogrenciler[i]);
        }   
    } else if (secim == 2) {
        // Manuel giriş seçeneği
        for (int i = 0; i < 100; ++i) {
            cout << i + 1 << ". öğrenciyi girin:" << endl;
            ogrenciler[i] = manuelOgrenciGiris(i + 1);

            // Yıl içi notunu ve başarı notunu hesapla
            ogrenciler[i].yilIciNotu = yilIciNotuHesapla(ogrenciler[i]);
            ogrenciler[i].basariNotu = basariNotuHesapla(ogrenciler[i]);

        }
    } else {
        cout << "Geçersiz seçim!" << endl;
        return 1;
    }

    

    int secim2;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1 - Sınıfın Listesi Yazdır\n";
        cout << "2 - En Yüksek Not Hesapla\n";
        cout << "3 - En Düşük Not Hesapla\n";
        cout << "4 - Sınıf Ortalaması Hesapla\n";
        cout << "5 - Sınıf Standart Sapması Hesapla\n";
        cout << "6 - Belirli Not Aralığında Olanlar\n";
        cout << "7 - Belirli Değerin Altında Olanlar\n";
        cout << "8 - Belirli Değerin Üstünde Olanlar\n";
        cout << "0 - Çıkış\n";
        cout << "Seçiminiz: ";
        cin >> secim2;

        switch (secim2) {
        case 1:
            sinifListesiYazdir(ogrenciler);
            break;
        case 2:
            cout << "En Yüksek Not: " << enYuksekNotHesapla(ogrenciler) << endl;
            break;
        case 3:
            cout << "En Düşük Not: " << enDusukNotHesapla(ogrenciler) << endl;
            break;
        case 4:
            cout << "Sınıf Ortalaması: " << snifOrtalamasiHesapla(ogrenciler) << endl;
            break;
        case 5:
            cout << "Sınıf Standart Sapması: " << sinifStandartSapmasiHesapla(ogrenciler) << endl;
            break;
        case 6: {
            float minNot, maxNot;
            cout << "Minimum not aralığı: ";
            cin >> minNot;
            cout << "Maksimum not aralığı: ";
            cin >> maxNot;
            notAraligindaOgrenciler(ogrenciler, minNot, maxNot);
            break;
        }
        case 7: {
            float maxNot;
            cout << "Maksimum not değeri: ";
            cin >> maxNot;
            belirliDegerAltindaOgrenciler(ogrenciler, maxNot);
            break;
        }
        case 8: {
            float minNot;
            cout << "Minimum not değeri: ";
            cin >> minNot;
            belirliDegerUstundeOgrenciler(ogrenciler, minNot);
            break;
        }
        case 0:
            cout << "Programdan çıkılıyor." << endl;
            return 0;
            break;
        default:
            cout << "Geçersiz seçim, tekrar deneyin." << endl;
        }

    } while (secim != 0);

}



string notuHarfDerecesineCevir(float notYuzde) {
    if (notYuzde >= 90) {
        return "AA";
    }
    else if (notYuzde >= 85) {
        return "BA";
    }
    else if (notYuzde >= 80) {
        return "BB";
    }
    else if (notYuzde >= 75) {
        return "CB";
    }
    else if (notYuzde >= 70) {
        return "CC";
    }
    else if (notYuzde >= 65) {
        return "DC";
    }
    else if (notYuzde >= 60) {
        return "DD";
    }
    else if (notYuzde >= 55) {
        return "FD";
    }
    else {
        return "FF";
    }

}

// Notu doğrulayan fonksiyon (0 ile 100 arasında olup olmadığını kontrol eder)
float notuDogrula() {
    float notDegeri;
    do {
        cout << "Notu giriniz (0-100 arası): ";
        cin >> notDegeri;
        if (notDegeri < 0 || notDegeri > 100) {
            cout << "Geçersiz not! Not 0 ile 100 arasında olmalıdır." << endl;
        }
    } while (notDegeri < 0 || notDegeri > 100);
    return notDegeri;
}

// Öğrenci bilgilerini rastgele atama fonksiyonu
Ogrenci rastgeleOgrenciAta(const string isimler[], const string soyisimler[], int ogrenciNo) {
    Ogrenci ogrenci;
    ogrenci.adi = isimler[rand() % 30];
    ogrenci.soyadi = soyisimler[rand() % 30];
    ogrenci.no = ogrenciNo;
    ogrenci.dogumTarihi.gun = 1 + rand() % 30;
    ogrenci.dogumTarihi.ay = 1 + rand() % 12;
    ogrenci.dogumTarihi.yil = 1995 + rand() % 10;

    return ogrenci;
}

// Rastgele bir not üretmek için belirtilen aralık ve yüzdelik dilimlere göre not dağılımı yapacak fonksiyon
vector<float> notDagilimi(int toplamOgrenci) {
    vector<float> notlar;

    // %10'unu 0-40 arasında atıyoruz
    for (int i = 0; i < toplamOgrenci * 0.1; i++) {
        notlar.push_back(rand() % 41); // 0 ile 40 arası
    }

    // %50'sini 40-70 arasında atıyoruz
    for (int i = 0; i < toplamOgrenci * 0.5; i++) {
        notlar.push_back(40 + rand() % 31); // 40 ile 70 arası
    }

    // %15'ini 70-80 arasında atıyoruz
    for (int i = 0; i < toplamOgrenci * 0.15; i++) {
        notlar.push_back(70 + rand() % 11); // 70 ile 80 arası
    }

    // %25'ini 80-100 arasında atıyoruz
    for (int i = 0; i < toplamOgrenci * 0.25; i++) {
        notlar.push_back(80 + rand() % 21); // 80 ile 100 arası
    }

    // Notları karıştırıyoruz
    random_device rd;
    mt19937 g(rd());
    shuffle(notlar.begin(), notlar.end(), g);

    return notlar;
}

// Öğrenci bilgilerini manuel olarak alır

Ogrenci manuelOgrenciGiris(int ogrenciNo) {
    Ogrenci ogrenci;
    ogrenci.no = ogrenciNo;

    cout << "Öğrenci adı: ";
    cin >> ogrenci.adi;

    cout << "Öğrenci soyadı: ";
    cin >> ogrenci.soyadi;

    cout << "Doğum günü (1-31): ";
    cin >> ogrenci.dogumTarihi.gun;

    cout << "Doğum ayı (1-12): ";
    cin >> ogrenci.dogumTarihi.ay;

    cout << "Doğum yılı: ";
    cin >> ogrenci.dogumTarihi.yil;

    // Notları alıyoruz ve her bir not için doğrulama yapıyoruz
    cout << "Kısa Sınav1 : ";
    ogrenci.kisaSinav1 = notuDogrula();

    cout << "Kısa Sınav 2: ";
    ogrenci.kisaSinav2 = notuDogrula();

    cout << "Ödev 1: ";
    ogrenci.odev1 = notuDogrula();

    cout << "Ödev 2: ";
    ogrenci.odev2 = notuDogrula();

    cout << "Proje: ";
    ogrenci.proje = notuDogrula();

    cout << "Vize: ";
    ogrenci.vize = notuDogrula();

    cout << "Final: ";
    ogrenci.final = notuDogrula();

    return ogrenci;
}

// Yıl içi notunu hesaplayan fonksiyon
float yilIciNotuHesapla(const Ogrenci& ogrenci) {
    return (ogrenci.vize * 0.50) + (ogrenci.kisaSinav1 * 0.07) + (ogrenci.kisaSinav2 * 0.07) +
        (ogrenci.odev1 * 0.10) + (ogrenci.odev2 * 0.10) + (ogrenci.proje * 0.16);
}

// Başarı notunu hesaplayan fonksiyon
float basariNotuHesapla(const Ogrenci& ogrenci) {
    return (ogrenci.yilIciNotu * 0.55) + (ogrenci.final * 0.45);
}


void sinifListesiYazdir(const Ogrenci ogrenciler[]) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        cout << "No: " << ogrenciler[i].no << ", Adı: " << ogrenciler[i].adi
            << ", Soyadı: " << ogrenciler[i].soyadi << ", Başarı Notu: "
            << ogrenciler[i].basariNotu << endl;
    }
    count++;
    if (count == 20) {
        cout << "\nDevam etmek için bir tuşa basın...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        count = 0;
    }
}

float enYuksekNotHesapla(const Ogrenci ogrenciler[]) {
    float maxNot = ogrenciler[0].basariNotu;
    for (int i = 1; i < 100; i++) {
        if (ogrenciler[i].basariNotu > maxNot) {
            maxNot = ogrenciler[i].basariNotu;
        }
    }
    return maxNot;
}

float enDusukNotHesapla(const Ogrenci ogrenciler[]) {
    float minNot = ogrenciler[0].basariNotu;
    for (int i = 1; i < 100; i++) {
        if (ogrenciler[i].basariNotu < minNot) {
            minNot = ogrenciler[i].basariNotu;
        }
    }
    return minNot;
}

float snifOrtalamasiHesapla(const Ogrenci ogrenciler[]) {
    float toplam = 0.0;
    for (int i = 0; i < 100; i++) {
        toplam += ogrenciler[i].basariNotu; 
    }
    return toplam / 100;
}

float sinifStandartSapmasiHesapla(const Ogrenci ogrenciler[]) {
    float ortalama = snifOrtalamasiHesapla(ogrenciler);
    float toplam = 0.0;
    for (int i = 0; i < 100; i++) {
        toplam += pow(ogrenciler[i].basariNotu - ortalama, 2);
    }
    return sqrt(toplam / 100);
}

void notAraligindaOgrenciler(const Ogrenci ogrenciler[], float minNot, float maxNot) {
    for (int i = 0; i < 100; i++) {
        if (ogrenciler[i].basariNotu >= minNot && ogrenciler[i].basariNotu < maxNot) {
            cout << "No: " << ogrenciler[i].soyadi << ", Başarı Notu: "
                << ogrenciler[i].basariNotu << endl;
        }
    }
}

void belirliDegerAltindaOgrenciler(const Ogrenci ogrenciler[], float maxNot) {
    for (int i = 0; i < 100; ++i) {
        if (ogrenciler[i].basariNotu < maxNot) {
            cout << "No: " << ogrenciler[i].no << ", Adı: " << ogrenciler[i].adi
                << ", Soyadı: " << ogrenciler[i].soyadi << ", Başarı Notu: "
                << ogrenciler[i].basariNotu << endl;
        }
    }
}

void belirliDegerUstundeOgrenciler(const Ogrenci ogrenciler[], float minNot) {
    for (int i = 0; i < 100; ++i) {
        if (ogrenciler[i].basariNotu > minNot) {
            cout << "No: " << ogrenciler[i].no << ", Adı: " << ogrenciler[i].adi
                << ", Soyadı: " << ogrenciler[i].soyadi << ", Başarı Notu: "
                << ogrenciler[i].basariNotu << endl;
        }
    }
}
