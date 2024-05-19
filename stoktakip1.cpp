#include "stoktakip1.h"
using namespace std;
// Urun sınıfı üye fonksiyonlarının tanımları
Urun::Urun(const string& ad, double miktar) : ad(ad), miktar(miktar) {}

string Urun::getAd() const { return ad; }
double Urun::getMiktar() const { return miktar; }
void Urun::setMiktar(double miktar) { this->miktar = miktar; }

// StokTakip sınıfı üye fonksiyonlarının tanımları
StokTakip::StokTakip() {
    // Varsayılan stok miktarı
    urunler.push_back(Urun("Et", 100));
    urunler.push_back(Urun("Köfte", 100));
    urunler.push_back(Urun("Lavaş", 100));
    urunler.push_back(Urun("Biber", 100));
    urunler.push_back(Urun("Domates", 100));
}

void StokTakip::urunEkle(const Urun& urun) {
    // Eğer ürün zaten stokta varsa miktarını arttır
    for (auto& u : urunler) {
        if (u.getAd() == urun.getAd()) {
            u.setMiktar(u.getMiktar() + urun.getMiktar());
            return;
        }
    }
    // Eğer ürün stokta yoksa yeni ürün olarak ekle
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
        // Burada her bir ürünün miktarı ile fiyatı toplanabilir
        // Ancak fiyat bilgisi olmadığı için sadece miktarı ile işlem yapacağız
        toplam += urun.getMiktar();
    }
    return toplam;
}
