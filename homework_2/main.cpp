#include <iostream> // Ekrana yazd�rma i�lemleri (cout, wcout) i�in gerekli
#include <fstream> // Dosya i�lemleri (ifstream, ofstream) i�in gerekli
#include <vector> // Dinamik dizi yap�s� (vector) kullanmak i�in gerekli
#include <string> // Metin i�lemleri (string, wstring) i�in gerekli
#include <locale> // Dil ve karakter kodlamas� ayarlar� i�in gerekli
#include <algorithm> // find ve transform gibi algoritmalar i�in gerekli
#include <ctime> // Zaman tabanl� i�lemler (time, srand) i�in gerekli
#include <cwctype> // Geni� karakter i�lemleri (towlower) i�in gerekli


using namespace std;

// Ge�erli bir il ismi olup olmad���n� kontrol etmek i�in bir fonksiyon
bool isIlIsmi(const wstring& isim, const vector<wstring>& iller) {
    // isim ve iller'deki her bir il ismini k���k harfe �evirerek kar��la�t�rma yapal�m
    wstring isim_lower = isim;
    transform(isim_lower.begin(), isim_lower.end(), isim_lower.begin(), towlower);

    for (const wstring& il : iller) {
        wstring il_lower = il;
        transform(il_lower.begin(), il_lower.end(), il_lower.begin(), towlower);
        if (isim_lower == il_lower) {
            return true;
        }
    }
    return false;
}

int main() {
    locale::global(locale("tr_TR.UTF-8"));

    vector<wstring> iller;
    wifstream dosya("liste.txt");

    // Dosyan�n UTF-8 karakter kodlamas�nda a��lmas�n� sa�la
    dosya.imbue(locale("tr_TR.UTF-8"));

    if (dosya.is_open()) {
        wstring il;
        while (getline(dosya, il)) {
            // Sat�r sonundaki t�m bo�luk ve �zel karakterleri temizle
            il.erase(remove_if(il.begin(), il.end(), [](wchar_t ch) {
                return iswspace(ch) || ch == L'\r' || ch == L'\n';
                }), il.end());

            iller.push_back(il);
        }
        dosya.close();
    }
    else {
        cerr << "Dosya a��lamad�!" << endl;
        return 1;
    }

    if (iller.empty()) {
        cerr << "�ller listesi bo�!" << endl;
        return 1;
    }

    // En k�sa ve en uzun karakter say�s�n� saklamak i�in de�i�kenler
    int minLength = iller[0].length();
    int maxLength = iller[0].length();

    for (const wstring& il : iller) {
        int length = il.length();
        if (length < minLength) minLength = length;
        if (length > maxLength) maxLength = length;
    }

    wcout << L"En k�sa karakter uzunlu�u: " << minLength << endl;
    wcout << L"En uzun karakter uzunlu�u: " << maxLength << endl;

    // Rastgele se�im i�lemleri i�in
    srand(static_cast<unsigned int>(time(0)));

    for (int currentLength = minLength; currentLength <= maxLength; ++currentLength) {
        bool found = false;
        unsigned int attempts = 0;

        while (!found && attempts < 100000) {
            vector<wstring> secilenIller;

            for (int i = 0; i < currentLength; ++i) {
                int randomIndex = rand() % iller.size();
                secilenIller.push_back(iller[randomIndex]);
            }

            for (int i = 0; i < currentLength; ++i) {
                wstring olusacakIsim;
                bool valid = true;

                for (const wstring& il : secilenIller) {
                    if (il.length() > i) {
                        olusacakIsim += il[i];
                    }
                    else {
                        valid = false;
                        break;
                    }
                }

                if (valid && isIlIsmi(olusacakIsim, iller)) {
                    wcout << currentLength << L" karakterli bulunan il ismi: " << olusacakIsim << endl;
                    found = true;
                    break;
                }
            }

            ++attempts;
        }

        if (!found) {
            wcout << currentLength << L" karakterli il ismi bulunamad�." << endl;
        }
    }

    return 0;
}
