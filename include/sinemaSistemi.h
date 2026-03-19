/*
*@file sinemaSistemi.h
*@description - sinemaSistemi sınııfını tanımlar ve film,salon,seans ve bilet işlemleri yönetmek için gerekli fanksiyonların tanımlar
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#ifndef SINEMASISTEMI_H
#define SINEMASISTEMI_H

#include <iostream>
#include <string>
#include "film.h"
#include "bilet.h"
#include "sinemaSalonu.h"
using namespace std;

class sinemaSistemi{
private:
     Film **filmler;
     int filmSayisi;
     sinemaSalonu **salonlar;
     int salonSayisi;
     Bilet **biletler;
     int biletSayisi;
     
public:
     sinemaSistemi(); //yapıcı metod - constructor
     ~sinemaSistemi(); //yıkıcı metod - destructor

     //getter metotları
     int getFilmSayisi() const;
     int getSalonSayisi() const;

     //salonları karşılaştırma fonksiyonları
     sinemaSalonu *enBuyukSalon() const;
     void salonlariSirala();
     bool salonlarEsitMi(const string &salonAdi1, const string &salonAdi2) const;
     void kapasiteUstuSalonlar(int kapasiteLimiti) const;
     void kapasiteAltiSalonlar(int kapasiteLimiti) const;

     //film işlemleri
     Film* getFilm(const string &filmAdi); //normal versiyon, değiştirilebilir Film* döndürür
     const Film* getFilm(const string &filmAdi) const; //const versiyon, Film değiştirilemez, sadece okunur
     void filmEkle(Film *film);
     void filmSil(const string &filmAdi);
     void filmGuncelle(const string &filmAdi, Film *yeniFilm);
     void filmleriGoster() const;
     void filmleriDosyayaYaz() const;
     void filmleriDosyadanOku();

     //salon işlemleri
     void salonEkle(sinemaSalonu *salon);
     void salonSil(const string  &salonAdi);
     void salonGuncelle(const string &salonAdi, sinemaSalonu *yeniSalon);
     sinemaSalonu *getSalon(const string &salonAdi) const; //salon bulma işlemi yapan fon
     void salonlariGoster() const;
     void salonlariDosyayaYaz() const;
     void salonlariDosyadanOku();

     //seans işlemleri
     void seansEkle(const string &filmAdi, const string &seans);
     void seansGuncelle(const string &filmAdi, const string &eskiSeans, const string &yeniSeans);
     void seansSil(const string &filmAdi, const string &seans);

     //bilet işelmleri
     void biletKaydet(Bilet *bilet);
     void biletSat(Musteri *mustrei, Film *film, sinemaSalonu *salon, int koltukNo);
     void biletleriListele() const;
     void biletleriDosyayaYaz() const;
     void biletleriDosyadanOku();
};

#endif