/*
*@file test.cpp
*@description - yazılan tüm nesneler ve metotların testi
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

void testSinemaSistemi(){

     //sinema sistemini tanımlama
     sinemaSistemi sistem;
     Admin admin1("admin1","1234");

     //film ekleme testi
     Film *film1=new Film("truman show",13,"20:00");
     Film *film2=new Film("matrix",-1,"22:00");
     Film *film3=new Film("titanic",18,"18:00");
     cout<<"----- Film ekleme testi----------"<<endl;
     sistem.filmEkle(film1);
     sistem.filmEkle(film2);
     sistem.filmEkle(film3);
     cout<<"------------------------------"<<endl;
     sistem.filmleriGoster();

     //film güncelleme testi
     cout<<"-----guncellemeden onceki film listesi----------"<<endl;
     sistem.filmleriGoster();
     cout<<"------titanic film guncelleme------"<<endl;
     sistem.filmGuncelle("titanic", new Film("titanic",13,"20:00"));
     cout<<"------------------------------"<<endl;
     cout<<"-----guncellemeden sonraki film listesi----------"<<endl;
     sistem.filmleriGoster();

     //film silme testi
     Film *film6=new Film("ornekFilm",10,"20:00");
     sistem.filmEkle(film6);
     cout<<"-----silme isleminden onceki film listesi----------"<<endl;
     sistem.filmleriGoster();
     cout<<"------ornekFilm filmi silme------"<<endl;
     sistem.filmSil("ornekFilm");
     cout<<"------------------------------"<<endl;
     cout<<"-----silme isleminden sonraki film listesi----------"<<endl;
     sistem.filmleriGoster();

     //film bulma (getFilm) testi
     cout<<"--film bulma testleri--\n";
     Film *bulunanFilm=sistem.getFilm("titanic");
     if (bulunanFilm)
     {
          cout<<"basarili, film bulundu"<<endl;
     }else{
          cout<<"basarisiz, film bulunamadi"<<endl;
     }
     cout<<"------------------------------"<<endl;
     //olmayan bir filmi arama
     Film *olmayanFilm=sistem.getFilm("ornekFilm");
     if (olmayanFilm)
     {
          cout<<"basarili, film bulundu"<<endl;
     }else{
          cout<<"basarisiz, film bulunamadi"<<endl;
     }
     cout<<"------------------------------"<<endl;

     //salon ekleme testi
     sinemaSalonu *salon1=new sinemaSalonu("salon A",10);
     sinemaSalonu *salon2=new sinemaSalonu("salon B",50);
     sinemaSalonu *salon3=new sinemaSalonu("salon C",250);
     sinemaSalonu *salon4=new sinemaSalonu("salon D",75);

     cout<<"----- Salon Ekleme Tesi----------"<<endl;
     sistem.salonEkle(salon1);
     sistem.salonEkle(salon2);
     sistem.salonEkle(salon3);
     sistem.salonEkle(salon4);
     cout<<"------------------------------"<<endl;
     salon1->salonDetaylariGoster();

     //salon güncelleme testi
     cout<<"-----guncellemeden onceki salon listesi----------"<<endl;
     sistem.salonlariGoster();
     sinemaSalonu *guncelSalon=new sinemaSalonu("salon D",150);
     sistem.salonEkle(guncelSalon);
     cout<<"------------------------------"<<endl;
     cout<<"-----guncellemeden sonraki film listesi----------"<<endl;
     sistem.salonlariGoster();

     //salon silme testi
     cout<<"-----silme isleminden onceki film listesi----------"<<endl;
     sinemaSalonu *salonS=new sinemaSalonu("salon S",100);
     sistem.salonEkle(salonS);
     cout<<"------------------------------"<<endl;
     sistem.salonlariGoster();

     sistem.salonSil("salon S");
     cout<<"-----silme isleminden sonraki film listesi----------"<<endl;
     sistem.salonlariGoster();

     //getSalon salon bulma testi
     cout<<"--salon bulma testleri--\n";
     sinemaSalonu *bulunanSalon=sistem.getSalon("salon B");
     if (bulunanSalon)
     {
          cout<<"basarili, salon bulundu"<<endl;
     }else{
          cout<<"basarisiz, salon bulunamadi"<<endl;
     }
     cout<<"------------------------------"<<endl;
     //olmayan bir salon arama
     sinemaSalonu *olmayanSalon=sistem.getSalon("salon S");
     if (olmayanSalon)
     {
          cout<<"basarili, salon bulundu"<<endl;
     }else{
          cout<<"basarisiz, salon bulunamadi"<<endl;
     }
     cout<<"------------------------------"<<endl;

     //seans ekleme
     cout<<"Seans ekleme testi: "<<endl;
     sistem.seansEkle("matrix","20:00");
     cout<<"------------------------------"<<endl;
     //seans güncelleme
     cout<<"Seans gucelleme testi: "<<endl;
     sistem.seansGuncelle("matrix","22:00","22:30");
     cout<<"------------------------------"<<endl;
     //seans silme
     cout<<"Seans silme testi: "<<endl;
     sistem.seansSil("matrix","20:00");
     cout<<"------------------------------"<<endl;

     //salon karşılaştırma testleri
     //en büyük kapasiteye sahip salon bulma testi
     sinemaSalonu *enBuyuk=sistem.enBuyukSalon();
     if (enBuyuk)
     {
          cout<<"En buyuk kapasiteye sahip salon: "<<enBuyuk->getSalonAdi()<<endl;
     }
     cout<<"------------------------------"<<endl;

     //küçükten büyüğe doğru sıralama testi
     sistem.salonlariSirala();
     sistem.salonlariGoster();
     cout<<"------------------------------"<<endl;

     //salonlar eşit mi testi
     if (sistem.salonlarEsitMi("salon A", "salon B"))
     {
          cout<<"girilen iki salon ayni kapasiteye sahip"<<endl;
     }else{
          cout<<"salonlar farkli kapasitelere sahip"<<endl;
     }
     cout<<"------------------------------"<<endl;

     //kapasite altı salaon listeleme testi
     sistem.kapasiteAltiSalonlar(100);
     cout<<"------------------------------"<<endl;

     //kapasite üstü salaon listeleme testi
     sistem.kapasiteUstuSalonlar(200);
     cout<<"------------------------------"<<endl;

     //musteri bilgileri testi
     Musteri *musteri1=new  TamBiletMusteri("Abidin");
     Musteri *musteri2=new Ogrenci("Mustafa");
     Musteri *musteri3=new Ogrenci("Muhammed");

     //bilet oluşturma testi
     Bilet *bilet=new Bilet(film1,musteri2,salon2,2);

     //koltuk rezervasyon testi sinemaSalonu da
     cout<<"----koltuk rezerve testi----\n";
          //salon 1 kapasitesi 10
     bool rezerve1=salon1->koltukRezerveEt(3);
     cout<<"\n"<<endl;
     bool rezerve2=salon1->koltukRezerveEt(6);
     cout<<"\n"<<endl;
          //yeterli boş koltuk kalmadı
     bool rezerve3=salon1->koltukRezerveEt(4);
     cout<<"\n"<<endl;
          //kalan 1 koltuk rezervasyonu
     bool rezerve4=salon1->koltukRezerveEt(1);
     cout<<"\n"<<endl;
          //salon doldu
     bool rezerve5=salon1->koltukRezerveEt(4);
     cout<<"------------------------------"<<endl;
     


     //bilet satma testi
     sistem.biletSat(musteri1, film1, salon2, 3);
     cout<<"------------------------------"<<endl;

     //bilet listeleme testi
     sistem.biletleriListele();
     cout<<"------------------------------"<<endl;

     //dosya işlemleri testi
     sistem.filmleriDosyayaYaz();
     sistem.salonlariDosyayaYaz();
     sistem.biletleriDosyayaYaz();
     sistem.filmleriDosyadanOku();
     sistem.salonlariDosyadanOku();
     sistem.biletleriDosyadanOku();
}