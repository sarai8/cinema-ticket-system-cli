/*
*@file admin.h
*@description - Admin sınııfını tanımlar ve film,salon ve seans işlemleri yönetmek için gerekli fanksiyonları tanımlar
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "kullanici.h"
#include "sinemaSistemi.h"
using namespace std;

class Admin: public Kullanici{
private:
     string kullaniciAdi;
     string sifre;
public:
     //constructor
     Admin(string kAdi, string sifre);
     
     //film işlemleri
     void filmEkle(sinemaSistemi &sistem, Film *film);
     void filmGuncelle(sinemaSistemi &sistem, Film *film);
     void filmSil(sinemaSistemi &sistem, const string &filmAdi);

     //salon işlemleri
     void salonEkle(sinemaSistemi &sistem, sinemaSalonu *salon);
     void salonGuncelle(sinemaSistemi &sistem, sinemaSalonu *salon);
     void salonSil(sinemaSistemi &sistem, const string &salonAdi);

     //seans işlemleri
     void seansEkle(sinemaSistemi &sistem, const string &filmAdi, const string &seans);
     void seansGuncelle(sinemaSistemi &sistem, const string &filmAdi, const string &eskiSeans, const string &yeniSeans);
     void seansSil(sinemaSistemi &sistem, const string &filmAdi, const string &seans);

     //admin bilgilerini yazar
     void kullaniciBilgileriGoster() const override;
};

#endif