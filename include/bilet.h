/*
*@file bilet.h
*@description - Bilet sınııfını tanımlar ve bilet işlemleri için gerekli fanksiyonları tanımlar
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#ifndef BILET_H
#define BILET_H

#include <iostream>
#include <string>
#include "film.h"
#include "musteri.h"
#include "sinemaSalonu.h"
using namespace std;

class Bilet{
     private:
          Film *film;
          Musteri *musteri;
          sinemaSalonu *salon;
          double fiyat;
          int koltukNo;

     public:
          //constructor
          Bilet(Film *film, Musteri *musteri, sinemaSalonu *salon, int koltukNo);

          Film *getFilm() const;
          Musteri *getMusteri() const;
          sinemaSalonu *getSalon() const;
          int getKoltukNo() const;
};
#endif