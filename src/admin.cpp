/*
*@file admin.cpp
*@description - Admin sınıfının metodlarıyla film,salon ve seans yönetimini sağlar 
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include "../include/admin.h"
#include "../include/sinemaSistemi.h"
#include <iostream>
#include <fstream>
using namespace std;

//constructor
Admin::Admin(string kAdi, string s): Kullanici(kAdi), sifre(s){}

//Admin tarafından
//film ekleme fonksiyonu
void Admin::filmEkle(sinemaSistemi &sistem, Film *film){
     sistem.filmEkle(film);
     cout<<"Eklenen film: "<<film->getFilmAdi()<<endl;
     sistem.filmleriDosyayaYaz();     
}

//film güncelleme fonksiyonu
void Admin::filmGuncelle(sinemaSistemi &sistem, Film *film){
     sistem.filmGuncelle(film->getFilmAdi(), film);
     sistem.filmleriDosyayaYaz();
}

//film silme fonksiyonu
void Admin::filmSil(sinemaSistemi &sistem, const string &filmAdi){
     sistem.filmSil(filmAdi);;
     sistem.filmleriDosyayaYaz();
}

//salon ekleme fonk
void Admin::salonEkle(sinemaSistemi &sistem, sinemaSalonu *salon){
     sistem.salonEkle(salon);
     sistem.salonlariDosyayaYaz();
}

//salon güncelleme fonk
void Admin::salonGuncelle(sinemaSistemi &sistem, sinemaSalonu *salon){
     sistem.salonGuncelle(salon->getSalonAdi(), salon);
     sistem.salonlariDosyayaYaz();
}

//salon silme fonk
void Admin::salonSil(sinemaSistemi &sistem, const string &salonAdi){
     sistem.salonSil(salonAdi);
     sistem.salonlariDosyayaYaz();
}

//seans ekleme fonksiyonu
void Admin::seansEkle(sinemaSistemi &sistem, const string &filmAdi, const string &seans){
     Film *film=sistem.getFilm(filmAdi);

     if (film==nullptr)
     {
          cout<<"film bulunamadi"<<endl;
          return;
     }
     film->seansEkle(seans);
     cout<<"Seans basariyla eklendi"<<endl;
     sistem.filmleriDosyayaYaz();
}

//seans güncelleme fonksiyonu
void Admin::seansGuncelle(sinemaSistemi &sistem, const string &filmAdi, const string &eskiSeans, const string &yeniSeans){
     Film *film=sistem.getFilm(filmAdi);

     if (film==nullptr)
     {
          cout<<"film bulunamadi"<<endl;
          return;
     }
     
     film->seansSil(eskiSeans);
     film->seansEkle(yeniSeans);
     cout<<"seans basariyla guncellendi: "<<eskiSeans<<"-->"<<yeniSeans<<endl;
     sistem.filmleriDosyayaYaz();
}

//seans silme fonksiyonu
void Admin::seansSil(sinemaSistemi &sistem, const string &filmAdi, const string &seans){
     Film *film=sistem.getFilm(filmAdi);

     if (film==nullptr)
     {
          cout<<"film bulunamadi"<<endl;
          return;
     }
     film->seansSil(seans);
     cout<<"Seans basariyla siilindi, silinen seans: "<<seans<<endl;
     sistem.filmleriDosyayaYaz();
}

//admin bilgilerini yazdırma
void Admin::kullaniciBilgileriGoster() const{
     cout<<"admin adi: "<<kullaniciAdi<<"\nSifre: "<<sifre<<endl;
}