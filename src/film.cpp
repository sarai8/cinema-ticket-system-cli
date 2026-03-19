/*
*@file film.cpp
*@description - Film sınıfının metodlarıyla film ve seans işlemleri yapar 
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include "../include/film.h"
#include <iostream>
using namespace std;

//yapıcı metod
Film:: Film(string filmAdi, int yasSiniri, string filmSeansi): filmAdi(filmAdi), yasSiniri(yasSiniri), seansSayisi(0),kapasite(2){
     filmSeanslari=new string[kapasite];
     seansEkle(filmSeansi);
}

Film::Film(string ad, int yasSiniri): filmAdi(ad), yasSiniri(yasSiniri),seansSayisi(0),kapasite(2){
     filmSeanslari=new string[kapasite];
}

//yıkıcı metod
Film::~Film(){
     delete[] filmSeanslari; 
}

//getter metodları
string Film::getFilmAdi() const{
     return filmAdi;
}
string Film::getFilmSeanslari() const{
     if (seansSayisi==0)
     {
          return "";//seans yoksa boş string 
     }

     string seanslar=filmSeanslari[0];
     for (int i = 1; i < seansSayisi; i++)
     {
          seanslar += ","+filmSeanslari[i];
     }
     return seanslar;
}
int Film::getSeansSayisi() const{
     return seansSayisi;
}
int Film::getYasSiniri() const{
     return yasSiniri;
}

//setter metodları
void Film::setFilmAdi(const string &yeniFilmAd){
     filmAdi=yeniFilmAd;
}
void Film::setYasSiniri(int yeniYasSiniri){
     yasSiniri=yeniYasSiniri;
}

//kapasite arttırma fonksiyonu
void Film::seansKapasiteArttir(){
     kapasite*=2; //kapasiteyi iki katına çıkar
     string *yeniSeanslar=new string[kapasite];

     for (int i = 0; i < seansSayisi; i++){
          yeniSeanslar[i]=filmSeanslari[i];
     }
     delete[] filmSeanslari; //eski belleği serbest bırak
     filmSeanslari=yeniSeanslar;     
     cout<<"Seans kapasitesi "<<kapasite<<" olarak guncellendi"<<endl;
}

//yeni seans ekleme fonksiyonu
void Film::seansEkle(const string &seans){
     if (seansSayisi==kapasite){
          seansKapasiteArttir();
     }
     filmSeanslari[seansSayisi++]= seans;     
}

//seansı güncelleme fonksiyonu
void Film::seansGuncelle(const string &eskiSeans, const string &yeniSeans){
     for (int i = 0; i < seansSayisi; i++)
     {
          if (filmSeanslari[i]==eskiSeans)
          {
               filmSeanslari[i]=yeniSeans;
               cout<<"Seans basariyla guncellendi: "<<eskiSeans<<" -->"<<yeniSeans<<endl;
               return;
          }
     }
     cout<<"Seans bulunamadi"<<endl;
}

//seans silme fonksiyonları
void Film::seansSil(const string &seans){
     for (int i = 0; i < seansSayisi; i++)
     {
          if (filmSeanslari[i]==seans)
          {
               for (int j = i; j < seansSayisi-1; j++)
               {
                    filmSeanslari[j]=filmSeanslari[j+1];
               }
               seansSayisi--;
               cout<<"Seans basariyla silindi, silinen seans: "<<seans<<endl;
               return;
          }
     }  
     cout<<"Seans bulunamadi"<<endl;
}

//film detaylarıını ekrana yazdırma fonksiyonu
void Film::filmDetaylariGoster() const{
     cout << "Film: "<< filmAdi<<endl;
      
     if (yasSiniri!=-1)
     {
          cout<<"Yas siniri: +"<<yasSiniri<<endl;
     }else{
          cout<<"Yas siniri yok"<<endl;
     }

     cout<<"Seanslar: ";
     for (int i = 0; i < seansSayisi; i++)
     {
          cout<<filmSeanslari[i]<<" ";
     }
     cout<<"\n------------------------------"<<endl;

}