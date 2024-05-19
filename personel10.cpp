#include "personel10.h"
#include <iostream>
using namespace std;

void PersonelEkleme::setAd(const string& ad) {
    this->ad = ad;
}

void PersonelEkleme::setSoyad(const string& soyad) {
    this->soyad = soyad;
}

void PersonelEkleme::setYas(int yas) {
    if (yas >= 1 && yas <= 100) {
        this->yas = yas;
    }
    else {
        cout << "Yas 1 ile 100 arasinda olmalidir. Tekrar deneyin: ";
        cin >> yas;
        setYas(yas);
    }
}

void PersonelEkleme::setTcNo(long int tcNo) {
    this->tcNo = tcNo;
}

void PersonelEkleme::setBoy(double boy) {
    this->boy = boy;
}

void PersonelEkleme::setAdres(const string& adres) {
    this->adres = adres;
}

void PersonelEkleme::setTelNo(long int telNo) {
    this->telNo = telNo;
}

string PersonelEkleme::getAd() const {
    return ad;
}

string PersonelEkleme::getSoyad() const {
    return soyad;
}

int PersonelEkleme::getYas() const {
    return yas;
}

int PersonelEkleme::getTcNo() const {
    return tcNo;
}

double PersonelEkleme::getBoy() const {
    return boy;
}

string PersonelEkleme::getAdres() const {
    return adres;
}

int PersonelEkleme::getTelNo() const {
    return telNo;
}

void PersonelEkleme::Yazdir() const {
    cout << "Personel Bilgileri:" << endl;
    cout << "Ad: " << ad << endl;
    cout << "Soyad: " << soyad << endl;
    cout << "Yas: " << yas << endl;
    cout << "TC No son iki rakam: " << tcNo << endl;
    cout << "Boy: " << boy << endl;
    cout << "Adres: " << adres << endl;
    cout << "Tel No son iki rakam: " << telNo << endl;
}

// Destructor
PersonelEkleme::~PersonelEkleme() {
    cout << "Personel bilgileri temizlendi." << endl;
}