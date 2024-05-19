#include <iostream>
#include <vector>
#include <string>
#include "personel10.h"
using namespace std;

class MasaTut {
public:
    static int MasaSec() {
        int MasaNo;
        cout << "Rezervasyon yapmak istediginiz masayi secin (1-10): ";
        cin >> MasaNo;
        return MasaNo;
    }
};

class MasaRezervasyonu {
private:
    int masa[10];

public:
    MasaRezervasyonu() {
        for (int i = 0; i < 10; i++) {
            masa[i] = 0;
        }
    }

    void MasaRezervasyon(int MasaNo) {
        if (MasaNo == -1) {
            cout << "Cikis Yapiliyor..." << endl;
        }
        else if (MasaNo < 1 || MasaNo > 10) {
            cout << "Boyle bir masa yok!" << endl;
        }
        else {
            cout << "Masa rezerve edildi." << endl;
        }
    }
};

class Siparis {
public:
    string yemekAdi;
    double fiyat;

    Siparis(string adi, double fyt) : yemekAdi(adi), fiyat(fyt) {}
};
class SiparisTakip {
private:
    vector<Siparis> siparisler;

public:
    void SiparisEkle(const Siparis& siparis) {
        siparisler.push_back(siparis);
    }

    void SiparisleriGoster() {
        cout << "Siparis Listesi:" << endl;
        for (size_t i = 0; i < siparisler.size(); ++i) {
            cout << siparisler[i].yemekAdi << " - " << siparisler[i].fiyat << " TL" << endl;
        }
    }

    double ToplamFiyat() const {
        double toplam = 0;
        for (size_t i = 0; i < siparisler.size(); ++i) {
            toplam += siparisler[i].fiyat;
        }
        return toplam;
    }
};



void MenuGoster() {
    cout << "Menü:" << endl;
    cout << "1. Hamburger - 150 TL" << endl;
    cout << "2. Adana Durum - 200 TL" << endl;
    cout << "3. Urfa Durum - 200 TL" << endl;
    cout << "4. Kebap - 250 TL" << endl;
    cout << "5. Corba - 100 TL" << endl;
}

Siparis YemekSec(int secim) {
    switch (secim) {
    case 1: return Siparis("Hamburger", 150.0);
    case 2: return Siparis("Adana Dürüm", 200.0);
    case 3: return Siparis("Urfa Dürüm", 200.0);
    case 4: return Siparis("Kebap", 250.0);
    case 5: return Siparis("Çorba", 100.0);
    default: return Siparis("Bilinmeyen", 0.0);
    }
}

void PersonelEkle() {
    PersonelEkleme personel;

    string ad, soyad, adres;
    int yas, tcNo, telNo;
    double boy;

    cout << "Personel Adini girin: ";
    cin >> ad;
    personel.setAd(ad);

    cout << "Personel Soyadini girin: ";
    cin >> soyad;
    personel.setSoyad(soyad);

    cout << "Personel Yasini girin: ";
    cin >> yas;
    personel.setYas(yas);

    cout << "Personel TC No son iki rakamini girin: ";
    cin >> tcNo;
    personel.setTcNo(tcNo);

    cout << "Personel Boyunu girin (metre olarak): ";
    cin >> boy;
    personel.setBoy(boy);

    cin.ignore(); // Önceki satýrdaki newline karakterini yoksaymak için
    cout << "Personel Adresini girin: ";
    getline(cin, adres); // getline kullanarak tam adresi aldým
    personel.setAdres(adres);

    cout << "Personel Tel No son iki rakamini girin: ";
    cin >> telNo;
    personel.setTelNo(telNo);

    personel.Yazdir();

    cout << "Personel kaydi yapildi." << endl;
}

int main() {
    MasaRezervasyonu rezervasyonSistemi;
    SiparisTakip siparisTakipSistemi;

    int secim;
    cout << "Masa rezervasyonu icin 1'e, personel eklemek icin 2'ye basin: ";
    cin >> secim;

    if (secim == 1) {
        int secilenMasa = MasaTut::MasaSec();
        rezervasyonSistemi.MasaRezervasyon(secilenMasa);

        if (secilenMasa != -1 && secilenMasa >= 1 && secilenMasa <= 10) {
            while (true) {
                MenuGoster();
                int yemekSecim;
                cout << "Siparis etmek istediginiz yemegi secin (1-5) veya cikmak icin -1: ";
                cin >> yemekSecim;

                if (yemekSecim == -1) {
                    break;
                }

                Siparis siparis = YemekSec(yemekSecim);
                if (siparis.fiyat > 0) {
                    siparisTakipSistemi.SiparisEkle(siparis);
                    cout << siparis.yemekAdi << " siparisi eklendi." << endl;
                }
                else {
                    cout << "Gecersiz secim, tekrar deneyin." << endl;
                }
            }

            siparisTakipSistemi.SiparisleriGoster();
            cout << "Toplam Fiyat: " << siparisTakipSistemi.ToplamFiyat() << " TL" << endl;
        }
    }
    else if (secim == 2) {
        PersonelEkle();
    }
    else {
        cout << "Gecersiz secim!" << endl;
    }

    return 0;
}
