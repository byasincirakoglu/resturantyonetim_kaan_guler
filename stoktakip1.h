#ifndef STOKTAKIP1_H
#define STOKTAKIP1_H
using namespace std;

#include <string>
#include <vector>
using namespace std;

class Urun {
private:
    string ad;
    double miktar; // Kilogram cinsinden

public:
    Urun(const string& ad, double miktar);

    string getAd() const;
    double getMiktar() const;
    void setMiktar(double miktar);
};

class StokTakip {
private:
    vector<Urun> urunler;

public:
    StokTakip();

    void urunEkle(const Urun& urun);
    void urunCikar(const string& ad, double miktar);
    void stokGoster() const;
    double toplamDeger() const;
};

#endif // STOKTAKIP_H
