#ifndef STOKTAKIP_H_
#define STOKTAKIP_H_

#include <string>
#include <vector>
using namespace std;

class Urun {
public:
    string isim;
    int miktar;
    double fiyat;

    Urun(string isim, int miktar, double fiyat)
        : isim(isim), miktar(miktar), fiyat(fiyat) {}
};

class StokTakip {
private:
    vector<Urun> urunler;

public:
    void urunEkle(const Urun& urun);
    void urunCikar(const string& isim, int miktar);
    void stokGoster() const;
    double toplamDeger() const;
};

#endif // STOKTAKIP_H_
