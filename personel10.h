#ifndef PERSONEL10_H_
#define PERSONEL10_H_

#include <string>
using namespace std;

class PersonelEkleme {
private:
    string ad;
    string soyad;
    int yas;
    int tcNo;
    double boy;
    string adres;
    int telNo;

public:
    void setAd(const string& ad);
    void setSoyad(const string& soyad);
    void setYas(int yas);
    void setTcNo(long int tcNo);
    void setBoy(double boy);
    void setAdres(const string& adres);
    void setTelNo(long int telNo);

    string getAd() const;
    string getSoyad() const;
    int getYas() const;
    int getTcNo() const;
    double getBoy() const;
    string getAdres() const;
    int getTelNo() const;

    void Yazdir() const;
    ~PersonelEkleme();
};

#endif // PERSONEL_H_
#pragma once
