#include "stoktakip1.h"
using namespace std;
// Urun s�n�f� �ye fonksiyonlar�n�n tan�mlar�
Urun::Urun(const string& ad, double miktar) : ad(ad), miktar(miktar) {}

string Urun::getAd() const { return ad; }
double Urun::getMiktar() const { return miktar; }
void Urun::setMiktar(double miktar) { this->miktar = miktar; }

// StokTakip s�n�f� �ye fonksiyonlar�n�n tan�mlar�
StokTakip::StokTakip() {
    // Varsay�lan stok miktar�
    urunler.push_back(Urun("Et", 100));
    urunler.push_back(Urun("K�fte", 100));
    urunler.push_back(Urun("Lava�", 100));
    urunler.push_back(Urun("Biber", 100));
    urunler.push_back(Urun("Domates", 100));
}

void StokTakip::urunEkle(const Urun& urun) {
    // E�er �r�n zaten stokta varsa miktar�n� artt�r
    for (auto& u : urunler) {
        if (u.getAd() == urun.getAd()) {
            u.setMiktar(u.getMiktar() + urun.getMiktar());
            return;
        }
    }
    // E�er �r�n stokta yoksa yeni �r�n olarak ekle
    urunler.push_back(urun);
}

void StokTakip::urunCikar(const string& ad, double miktar) {
    for (auto& urun : urunler) {
        if (urun.getAd() == ad) {
            if (urun.getMiktar() >= miktar) {
                urun.setMiktar(urun.getMiktar() - miktar);
                return;
            }
            else {
                cout << "Stokta yeterli miktar yok!" << endl;
                return;
            }
        }
    }
    cout << "Urun bulunamadi!" << endl;
}

void StokTakip::stokGoster() const {
    cout << "Stoktaki Urunler:" << endl;
    for (const auto& urun : urunler) {
        cout << "Ad: " << urun.getAd() << ", Miktar: " << urun.getMiktar() << " kg" << endl;
    }
}

double StokTakip::toplamDeger() const {
    double toplam = 0;
    for (const auto& urun : urunler) {
        // Burada her bir �r�n�n miktar� ile fiyat� toplanabilir
        // Ancak fiyat bilgisi olmad��� i�in sadece miktar� ile i�lem yapaca��z
        toplam += urun.getMiktar();
    }
    return toplam;
}
