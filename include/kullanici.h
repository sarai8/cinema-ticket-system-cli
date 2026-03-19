/*
*@file kullanici.h
*@description - Kullanici sınııfını tanımlar 
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#ifndef KULLANICI_H
#define KULLANICI_H

#include <iostream>
#include <string>
using namespace std;

class Kullanici{
     protected:
          string kullaniciAdi;
     public:
          //constructor
          Kullanici(string ad);

          //getter metodu
          string getKullaniciAdi() const;

          //sanal metod
          virtual void kullaniciBilgileriGoster() const=0; //saf sanal metot, alt sınıflar tarafından uygulanmalı
};

#endif