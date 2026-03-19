/*
*@file film.h
*@description - Film sınııfını tanımlar ve film,salon ve seans işlemleri yönetmek için gerekli fanksiyonları tanımlar
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#ifndef FILM_H
#define FILM_H
#include <iostream>
#include <string>
using namespace std;

class Film{
     private:
          string filmAdi;
          string *filmSeanslari;
          int seansSayisi, kapasite;
          int yasSiniri; //-1 ise yas sınırı yok
     public:
          //yapıcı metodu-constructor
          Film(string ad, int yas, string seans);
          Film(string ad="", int yasSiniri=-1);
          
          //yıkıcı metod-Destructor
          ~Film(); 

          //getter metodları
          string getFilmAdi() const;
          string getFilmSeanslari() const;
          int getSeansSayisi() const;
          int getYasSiniri() const;

          //setter metodları
          void setFilmAdi(const string &yeniAd);
          void setYasSiniri(int yeniYasSiniri);

          //seans işlemleri
          void seansEkle(const string &seans);
          void seansGuncelle(const string &eskiSeans, const string &yeniSeans);
          void seansSil(const string &seans);

          //kapasite arttırmak için
          void seansKapasiteArttir(); 

          //film bilgilerini ekrana yazdıran metod
          void filmDetaylariGoster() const;
};
#endif