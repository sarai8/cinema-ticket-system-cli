/*
*@file main.cpp
*@description - Sinema sistemi için oluşturulan metodları kullanıcılar kullanımı için menu haline getirilmiştir
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include <iostream>
#include "../include/test.h"
#include "../include/film.h"
#include "../include/bilet.h"
#include "../include/admin.h"
#include "../include/musteri.h"
#include "../include/sinemaSalonu.h"
#include "../include/sinemaSistemi.h"
using namespace std;

void adminFilmIslemleri(sinemaSistemi &sistem, Admin &admin){
     int secim;
     while (true)
     {
          cout<<"\n------ Film Islemleri ------"<<endl;
          cout<<"1- Film Ekle"<<endl;
          cout<<"2- Film Guncelle"<<endl;
          cout<<"3- Film Sil"<<endl;
          cout<<"4- Filmleri Listele"<<endl;
          cout<<"5- Geri Don"<<endl;
          cout<<"Yapmak istediginiz islemi seciniz: ";
          cin>> secim;
          cin.ignore();
          
          if (secim==1){
               //film ekleme
               string filmAdi, seans;
               int yasSiniri;

               cout<<"Film adi: ";
               getline(cin, filmAdi);

               cout<<"Yas siniri: ";
               cin>>yasSiniri;
               cin.ignore();

               cout<<"Seans saati: ";
               getline(cin, seans);

               admin.filmEkle(sistem, new Film(filmAdi, yasSiniri, seans));

          }else if(secim==2){
               //film güncelleme
               string filmAdi, yeniFilmAdi, yeniSeans;
               int yeniYasSiniri;

               cout<<"Guncellenecek filmin adini giriniz: ";
               getline(cin, filmAdi);

               Film *film= sistem.getFilm(filmAdi);
               if (film==nullptr)
               {
                    cout<<"Film bulunamadi"<<endl;
                    continue;
               }

               cout<<"Yeni film adini giriniz: ";
               getline(cin, yeniFilmAdi);

               cout<<"Yeni yas sinirini giriniz: ";
               cin>> yeniYasSiniri;
               cin.ignore();

               cout<<"Yeni seans saatini giriniz: ";
               getline(cin, yeniSeans);

               Film *yeniFilm=new Film(yeniFilmAdi, yeniYasSiniri, yeniSeans);

               admin.filmGuncelle(sistem, yeniFilm);
               
          }else if(secim==3){
               //film silme
               string filmAdi;

               cout<<"Silinecek filmin adini giriniz: ";
               getline(cin, filmAdi);

               admin.filmSil(sistem, filmAdi);

          }else if(secim==4){
               //filmleri listeleme
               sistem.filmleriGoster();

          }else if(secim==5){
               return;

          }else{
               cout<<"Gecersiz secim, tekrar seciniz."<<endl;
          }
     }
}

void adminSalonIslemleri(sinemaSistemi &sistem, Admin &admin){
     int secim;
     while (true)
     {
          cout<<"\n------ Salon Islemleri ------"<<endl;
          cout<<"1- Salon Ekle"<<endl;
          cout<<"2- Salon Guncelle"<<endl;
          cout<<"3- Salon Sil"<<endl;
          cout<<"4- Salonlari Listele"<<endl;
          cout<<"5- Geri Don"<<endl;
          cout<<"Yapmak istediginiz islemi seciniz: ";
          cin>> secim;
          cin.ignore();

          if (secim==1)
          {
               //salon ekle
               string salonAdi;
               int kapasite;

               cout<<"salon adini giriniz: ";
               getline(cin, salonAdi);

               cout<<"kapasitesini giriniz: ";
               cin>>kapasite;
               cin.ignore();
               
               admin.salonEkle(sistem, new sinemaSalonu(salonAdi, kapasite));

          }else if(secim==2){
               //salon guncelleme
               string salonAdi, yeniSalonAdi;
               int yeniKapasite;

               cout<<"Guncellenecek salon adini giriniz:";
               getline(cin, salonAdi);

               sinemaSalonu *salon=sistem.getSalon(salonAdi);
               if (salon==nullptr)
               {
                    cout<<"Salon bulunamadi"<<endl;
                    continue;
               }

               cout<<"Yeni salon adini giriniz: ";
               getline(cin, yeniSalonAdi);

               cout<<"yeni kapasite bilgisini giriniz: ";
               cin>>yeniKapasite;
               cin.ignore();

               sinemaSalonu *yeniSalon=new sinemaSalonu(yeniSalonAdi, yeniKapasite);
               admin.salonGuncelle(sistem, yeniSalon);

          }else if(secim==3){
               //salon silme
               string salonAdi;

               cout<<"Silinecek salon adini giriniz: ";
               getline(cin, salonAdi);

               admin.salonSil(sistem, salonAdi);

          }else if(secim==4){
               //salonları listeleme
               sistem.salonlariGoster();
               
          }else if(secim==5){
               return;

          }else{
               cout<<"Gecersiz secim, tekrar seciniz."<<endl;
          }
     } 
}

void adminSeansIslemleri(sinemaSistemi &sistem, Admin &admin){
     int secim;
     while (true)
     {
          cout<<"\n------ Seans Islemleri ------"<<endl;
          cout<<"1- Seans Ekle"<<endl;
          cout<<"2- Seans Guncelle"<<endl;
          cout<<"3- Seans Sil"<<endl;
          cout<<"4- Geri Don"<<endl;
          cout<<"Yapmak istediginiz islemi seciniz: ";
          cin>> secim;
          cin.ignore();

          if (secim==1)
          {
               //seans ekleme
               string filmAdi, seans;

               cout<<"Seans eklemek istediginiz film adini giriniz: ";
               getline(cin, filmAdi);

               Film *film= sistem.getFilm(filmAdi);
               if (film==nullptr)
               {
                    cout<<"film bulunamadi"<<endl;
                    continue;
               }

               cout<<"Eklemek istediginiz seans saatini giriniz: ";
               getline(cin, seans);

               admin.seansEkle(sistem, filmAdi, seans);
               
          }else if(secim==2){
               //seans güncelleme
               string filmAdi, eskiSeans, yeniSeans;

               cout<<"Seansi guncellenecek filmin adiini giriniz: ";
               getline(cin, filmAdi);

               cout<<"Guncellenecek seansi giriniz: ";
               getline(cin, eskiSeans);

               cout<<"Yeni seansi giriniz: ";
               getline(cin, yeniSeans);

               admin.seansGuncelle(sistem, filmAdi, eskiSeans, yeniSeans);

          }else if(secim==3){
               //seans silme
               string filmAdi, silinecekSeans;

               cout<<"Seansi silmek istediginiz filmin adini giriniz: ";
               getline(cin, filmAdi);
               
               Film *film= sistem.getFilm(filmAdi);
               if (film==nullptr)
               {
                    cout<<"Hata, film bulunamadi"<<endl;
                    continue;
               }

               cout<<"Silmek istediginiz seans saatini giriniz: ";
               getline(cin, silinecekSeans);

               admin.seansSil(sistem, filmAdi, silinecekSeans);
          
          }else if (secim==4){
               return;

          }else{
               cout<<"Gecersiz secim, tekrar seciniz."<<endl;
          } 
     }
}

// menu fonk - admin
void adminMenu(sinemaSistemi &sistem, Admin &admin){
     int secim;

     while (true)
     {
          cout<<"\n------ Admin Menusu ------"<<endl;
          cout<<"1- Film islemleri"<<endl;
          cout<<"2- Salon islemleri"<<endl;
          cout<<"3- Seans islemleri"<<endl;
          cout<<"4- Ana menuye don"<<endl;
          cout<<"Yapmak istediginiz islemi seciniz: ";
          cin>>secim;
          cin.ignore();

          if (secim==1){
               adminFilmIslemleri(sistem, admin);

          }else if(secim==2){
               adminSalonIslemleri(sistem, admin);

          }else if(secim==3){
               adminSeansIslemleri(sistem, admin);

          }else if(secim==4){
               return;

          }else{
               cout<<"Gecersiz secim, tekrar seciniz."<<endl;
          }     
     }  
}

void musteriMenu(sinemaSistemi &sistem){ 
     int secim;
  
     while (true)
     {
          cout<<"\n---------Musteri Menusu---------"<<endl;
          cout<<"1- Filmleri Listele"<<endl;
          cout<<"2- Salonlari Listele"<<endl;
          cout<<"3- Bilet Satin Al"<<endl;
          cout<<"4- Bilet Bilgisini Sorgula"<<endl;
          cout<<"5- Ana Menuye Don"<<endl;
          cout<<"Yapmak istediginiz islemi seciniz: ";
          cin>>secim;
          cin.ignore();

          if (secim==1){
               sistem.filmleriGoster();

          }else if(secim==2){
               sistem.salonlariGoster();
               
          }else if(secim==3){
               string musteriAdi, salonAdi, filmAdi, tip;
               int adet, koltukNo;

               sistem.salonlariGoster();

               cout<<"Adinizi giriniz: ";
               getline(cin, musteriAdi);

               cout<<"Salon adini giriniz: ";
               getline(cin, salonAdi);

               sinemaSalonu *secilenSalon=sistem.getSalon(salonAdi);
               if (secilenSalon==nullptr)
               {
                    cout<<"salon bulunamadi\n";
                    continue;
               }
               
               cout<<"Film adini giriniz: ";
               getline(cin, filmAdi);

               Film *secilenFilm=sistem.getFilm(filmAdi);
               if (secilenFilm==nullptr)
               {
                    cout<<"film bulunamadi\n";
                    continue;
               }

               cout<<"bilet tipini giriniz(ogrenci/tam): ";
               cin>> tip;
               cin.ignore();

               cout<<"Satin almak istediginiz bilet sayisini giriniz: ";
               cin>> adet;
               cin.ignore();

               cout<<"koltuk numarasini giriniz: ";
               cin>> koltukNo;
               cin.ignore();

               Musteri *musteri;
               if (tip == "ogrenci")
               {
                    musteri=new Ogrenci(musteriAdi);
               }else{
                    musteri=new TamBiletMusteri(musteriAdi);
               }

               //boş koltuk durumu kontrolü
               // if (secilenSalon->getBosKoltukSayisi()<adet)
               // {
               //      cout<<"Yeterli bos koltuk yok"<<endl;
               //      delete[] musteri;
               //      continue;
               // }

               //bilet satışı ve kaydetme
               if (secilenSalon->koltukRezerveEt(adet))
               {
                   for (int i = 0; i < adet; i++)
                   {
                       cout<<"koltuk numarasini giriniz: ";
                       cin>>koltukNo;
                       cin.ignore();
                    Bilet *yeniBilet=new Bilet(secilenFilm, musteri, secilenSalon,koltukNo);
                    sistem.biletKaydet(yeniBilet);
                   }
                    cout<<"bilet satin alma islemi basarili\n";
               }else{
                    cout<<"bilet satin alma islemi basarisiz"<<endl;
                       delete musteri;
               }
               
          }else if(secim==4){
               sistem.biletleriListele();

          } else if(secim==5){
               return;

          }else{
               cout<<"Gecersiz secim, tekrar seciniz."<<endl;
          }
     }  
}

int main(){

     int secim;
     cout<<"1- Ana menuyu baslat"<<endl;
     cout<<"2- Test modunu calistir"<<endl;
     cout<<"Yapmak istediginiz islemi seciniz: ";
     cin>>secim;

     if (secim==2)
     {
          cout<<"\n----Test modu acildi----\n";
          testSinemaSistemi();
          return 0; //testten sonra programı kapat
          
     }

     sinemaSistemi sistem;
     Admin admin("admin", "1234");

     sistem.filmleriDosyadanOku();
     sistem.salonlariDosyadanOku();
     sistem.biletleriDosyadanOku();

     while (true)
     {
          int girisSecimi;

          cout<<"\n1- Admin girisi"<<endl;
          cout<<"2- Musteri girisi"<<endl;
          cout<<"3- Cikis"<<endl;
          cout<<"Yapmak istediginiz islemi seciniz: ";
          cin>> girisSecimi;

          if (girisSecimi==1){
               string kullaniciAdi, sifre;

               cout<<"Kullanici adini giriniz: "; // endl?
               cin>> kullaniciAdi;

               cout<<"Sifreyi giriniz: ";
               cin>> sifre;

               if (kullaniciAdi=="admin" && sifre=="1234")
               {
                    adminMenu(sistem, admin);
               }else{
                    cout<<"Hatali giris yapildi"<<endl;
               }

          }else if(girisSecimi==2){
               musteriMenu(sistem);

          }else if(girisSecimi==3){
               cout<<"Programdan cikiliyor..."<<endl;
               break;

          }else{
               cout<<"Gecersiz secim"<<endl;
          }
     }
     return 0;
}