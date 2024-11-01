#include <iostream> // Ekrana yazdýrma iþlemleri (cout, wcout) için gerekli
#include <fstream> // Dosya iþlemleri (ifstream, ofstream) için gerekli
#include <vector> // Dinamik dizi yapýsý (vector) kullanmak için gerekli
#include <string> // Metin iþlemleri (string, wstring) için gerekli
#include <locale> // Dil ve karakter kodlamasý ayarlarý için gerekli
#include <algorithm> // find ve transform gibi algoritmalar için gerekli
#include <ctime> // Zaman tabanlý iþlemler (time, srand) için gerekli
#include <cwctype> // Geniþ karakter iþlemleri (towlower) için gerekli


using namespace std;

// Geçerli bir il ismi olup olmadýðýný kontrol etmek için bir fonksiyon
bool isIlIsmi(const wstring& isim, const vector<wstring>& iller) {
    // isim ve iller'deki her bir il ismini küçük harfe çevirerek karþýlaþtýrma yapalým
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

    // Dosyanýn UTF-8 karakter kodlamasýnda açýlmasýný saðla
    dosya.imbue(locale("tr_TR.UTF-8"));

    if (dosya.is_open()) {
        wstring il;
        while (getline(dosya, il)) {
            // Satýr sonundaki tüm boþluk ve özel karakterleri temizle
            il.erase(remove_if(il.begin(), il.end(), [](wchar_t ch) {
                return iswspace(ch) || ch == L'\r' || ch == L'\n';
                }), il.end());

            iller.push_back(il);
        }
        dosya.close();
    }
    else {
        cerr << "Dosya açýlamadý!" << endl;
        return 1;
    }

    if (iller.empty()) {
        cerr << "Ýller listesi boþ!" << endl;
        return 1;
    }

    // En kýsa ve en uzun karakter sayýsýný saklamak için deðiþkenler
    int minLength = iller[0].length();
    int maxLength = iller[0].length();

    for (const wstring& il : iller) {
        int length = il.length();
        if (length < minLength) minLength = length;
        if (length > maxLength) maxLength = length;
    }

    wcout << L"En kýsa karakter uzunluðu: " << minLength << endl;
    wcout << L"En uzun karakter uzunluðu: " << maxLength << endl;

    // Rastgele seçim iþlemleri için
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
            wcout << currentLength << L" karakterli il ismi bulunamadý." << endl;
        }
    }

    return 0;
}
