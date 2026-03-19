/*
*@file musteri.cpp
*@description - Musteri sınıfının metodlarıyla musteri işlemleri yapar
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include "../include/musteri.h"
#include <iostream>
using namespace std;

//constructor
Musteri::Musteri(string adi, string tipi): Kullanici(adi), musteriAdi(adi), musteriTipi(tipi){}

// getter metotları
string Musteri::getMusteriAdi() const{
     return musteriAdi;
}

//müşteri bilgilerini yazdırma fonksiyonu
void Musteri::kullaniciBilgileriGoster() const{
     cout<<"Musteri adi: "<< musteriAdi<<endl;
     cout<<"Musteri tipi: "<< musteriTipi<<endl;
}

double Musteri::biletFiyatiHesapla() const{
     return 150.0; //varsayılan bilet fiyatı
}

//ogrenci sınıfı
Ogrenci::Ogrenci(string ad): Musteri(ad, "ogrenci"){}

double Ogrenci::biletFiyatiHesapla() const{
     return 130.0;
}
string Ogrenci::getMusteriTipi() const{
     return "ogrenci";
}

//tamBiletMusteri sınıfı
TamBiletMusteri::TamBiletMusteri(string ad): Musteri(ad, "tam"){}

double TamBiletMusteri::biletFiyatiHesapla() const{
     return 150.0;
}

string TamBiletMusteri::getMusteriTipi() const{
     return "tam";
}