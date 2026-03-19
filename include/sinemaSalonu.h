/*
*@file sinemaSalonu.h
*@description - sinemaSalonu sınııfını tanımlar ve salon işlemleri yönetmek için gerekli fanksiyonları tanımlar
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#ifndef SINEMASALONU_H
#define SINEMASALONU_H

#include <iostream>
#include <string>
using namespace std;

class sinemaSalonu{
private:
     string salonAdi;
     int kapasite;
     int bosKoltukSayisi;

public:
     //constructor
     sinemaSalonu(string sAdi="", int kapasite=0);
     
     //getter metotları
     string getSalonAdi() const;
     int getKapasite() const;
     int getBosKoltukSayisi() const;

     //setter metotları
     void setKapasite(int yeniKapasite);
     void setSalonAdi(const string &yeniSalonAd);
     
     //koltuk rezervasyonu yapar
     bool koltukRezerveEt(int adet);
     
     //salon bilgilerini yazdırır
     void salonDetaylariGoster() const;

     //operator overriding(operator aşırı yükleme)- salon kapasitelerini karşılaştırmak için
     bool operator>(const sinemaSalonu &s)const;
     bool operator<(const sinemaSalonu &s)const; 
     bool operator==(const sinemaSalonu &s)const;
     bool operator>=(const sinemaSalonu &s)const;
     bool operator<=(const sinemaSalonu &s)const;   
};

#endif 