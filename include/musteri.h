/*
*@file musteri.h
*@description - mustrei sınııfını tanımlar ve Ogrenci ,TamBiletMusteri gibisınıfları barındırır
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#ifndef MUSTERI_H
#define MUSTERI_H

#include "kullanici.h"
#include <iostream>
#include <string>
using namespace std;

class Musteri: public Kullanici{
     private: 
          string musteriAdi;
          string musteriTipi; //ogrenci-tam

     public:
          //constructor
          Musteri(string ad, string tipi);

          //getter metotları
          string getMusteriAdi() const;

          //pure virtual -soyut- metotlar
          virtual string getMusteriTipi() const=0;
          virtual double biletFiyatiHesapla() const=0; 


          void kullaniciBilgileriGoster() const override;
};

class Ogrenci: public Musteri{
     public:
     Ogrenci(string ad);
     double biletFiyatiHesapla() const override;
     string getMusteriTipi() const override;
};

class TamBiletMusteri: public Musteri{
     public:
     TamBiletMusteri(string ad);
     double biletFiyatiHesapla() const override;
     string getMusteriTipi() const override;
};

#endif