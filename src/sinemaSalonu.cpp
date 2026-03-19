/*
*@file sinemaSalonu.cpp
*@description - sinemaSalonu sınıfının metodlarıyla salon yönetimini sağlar 
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include "../include/sinemaSalonu.h"
#include <iostream>
using namespace std;

//constructor
sinemaSalonu::sinemaSalonu(string sAdi, int kapasite):salonAdi(sAdi),kapasite(kapasite), bosKoltukSayisi(kapasite){}

//getter metotları
string sinemaSalonu::getSalonAdi() const{
     return salonAdi;
}
int sinemaSalonu::getKapasite() const{
     return kapasite;
}
int sinemaSalonu::getBosKoltukSayisi() const{
     return bosKoltukSayisi;
}

//setter metodları 
void sinemaSalonu::setSalonAdi(const string &yeniSalonAdi){
     salonAdi=yeniSalonAdi;
}
void sinemaSalonu::setKapasite(int yeniKapasite){
     kapasite=yeniKapasite;
     bosKoltukSayisi= yeniKapasite; //yeni kapasite belirlendiğinde boş koltuk sayısını da günceller
}

//koltuk rezervasyonu işlemi
bool sinemaSalonu::koltukRezerveEt(int adet){
     if (bosKoltukSayisi >= adet)
     {
          bosKoltukSayisi-=adet;
          cout<<adet<<" adet bilet satin alindi, kalan bos koltuk sayisi: "<<bosKoltukSayisi<<endl;
          return true;
     }else{
          cout<<"yeterli bos koltuk yok, mevcut bos koltuk sayisi: "<<bosKoltukSayisi<<endl;
          return false; 
     }
}

//salon bilgilerini yazdırır
void sinemaSalonu::salonDetaylariGoster() const{
     cout<<"Salon adi: "<<salonAdi<<endl;
     cout<<"Kapasitesi: "<<kapasite<<endl;
     cout<<"Bos koltuk sayisi: "<<bosKoltukSayisi<<endl;  
     cout<<"\n------------------------------"<<endl;
}

//operator overriding - operatör aşırı yükelme
bool sinemaSalonu::operator>(const sinemaSalonu &s)const{
     return kapasite>s.kapasite;
}

bool sinemaSalonu::operator<(const sinemaSalonu &s)const{
     return kapasite<s.kapasite;
}

bool sinemaSalonu::operator==(const sinemaSalonu &s)const{
     return kapasite==s.kapasite;
}

bool sinemaSalonu::operator>=(const sinemaSalonu &s)const{
     return kapasite>=s.kapasite;
}

bool sinemaSalonu::operator<=(const sinemaSalonu &s)const{
     return kapasite<=s.kapasite;
}