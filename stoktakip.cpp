#include "stoktakip.h"
#include <iostream>
using namespace std;

void StokTakip::urunEkle(const Urun& urun) {
    for (auto& u : urunler) {
        if (u.isim == urun.isim) {
            u.miktar += urun.miktar;
            return;
        }
    }
    urunler.push_back(urun);
}

void StokTakip::urunCikar(const string& isim, int miktar) {
    for (auto& u : urunler) {
        if (u.isim == isim) {
            if (u.miktar >= miktar) {
                u.miktar -= miktar;
            }
            else {
                cout << "Stokta yeterli miktar yok." << endl;
            }
            return;
        }
    }
    cout << "Urun bulunamadi." << endl;
}

void StokTakip::stokGoster() const {
    cout << "Stok Listesi:" << endl;
    for (const auto& u : urunler) {
        cout << u.isim << " - " << u.miktar << " adet - " << u.fiyat << " TL" << endl;
    }
}

double StokTakip::toplamDeger() const {
    double toplam = 0;
    for (const auto& u : urunler) {
        toplam += u.miktar * u.fiyat;
    }
    return toplam;
}
