/*
*@file sinemaSistemi.cpp
*@description - sinemaSistemi sınıfının metodlarıyla film,salon,seans ve bilet yönetimi için gerekli işlemleri sağlar 
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include "../include/sinemaSistemi.h"
#include "../include/sinemaSalonu.h"
#include "../include/bilet.h"
#include "../include/film.h"
#include <iostream>
#include <fstream>
using namespace std;

//constructor - film ve salon listesini oluşturma
sinemaSistemi::sinemaSistemi(){
     filmSayisi=0;
     salonSayisi=0;
     biletSayisi=0;
     filmler=new Film*[100];//max 100 tane film için
     salonlar=new sinemaSalonu*[100];//max 100 salon için
     biletler=new Bilet*[100]; 
}

//yıkıcı metod - bellekteki dinamik diziyi temizleme
sinemaSistemi::~sinemaSistemi(){
     for (int i = 0; i < filmSayisi; i++)
     {
          delete filmler[i];
     }
     delete[] filmler;

     for (int i = 0; i < salonSayisi; i++)
     {
          delete salonlar[i];
     }
     delete[] salonlar;

     for (int i = 0; i < biletSayisi; i++)
     {
          delete biletler[i];
     }
     delete[] biletler;
}

//getter m.
int sinemaSistemi::getFilmSayisi() const{
     return filmSayisi;
}
int sinemaSistemi::getSalonSayisi() const{
     return salonSayisi;
}

//salonları karşılaştırma fonksiyonları

//salonlar arasında en büyük kapasiteye sahip salon bulma
sinemaSalonu* sinemaSistemi::enBuyukSalon() const{
     if (salonSayisi==0)
     {
          cout<<"sistemde kayitli salon yok"<<endl;
          return nullptr;
     }

     sinemaSalonu *enBuyukSalon=salonlar[0];
     for (int i = 1; i < salonSayisi; i++)
     {
          if (*salonlar[i]>*enBuyukSalon) //">" operatörü kullanılıyor
          {
               enBuyukSalon=salonlar[i];
          }
     }
     return enBuyukSalon;
     
}

//salonları kapasiteye göre küçükten büyüğe sıralama
void sinemaSistemi::salonlariSirala(){
     if (salonSayisi==0)
     {
          cout<<"sistemde kayitli salon yok"<<endl;
          return;
     }

     for (int i = 0; i < salonSayisi-1; i++)
     {
          for (int j = i; j < salonSayisi; j++)
          {
               if (*salonlar[j]<*salonlar[i]) //"<" operatörü kullanılıyor
               {
                    swap(salonlar[i], salonlar[j]);
               }
          }
     }
     cout<<"salonlar kapasiteye gore siralandi"<<endl;
}

//girilen iki salonun kapasiteleri eşit mi
bool sinemaSistemi::salonlarEsitMi(const string &salonAdi1, const string &salonAdi2) const{
     sinemaSalonu *salon1=getSalon(salonAdi1);
     sinemaSalonu *salon2=getSalon(salonAdi2);

     if (!salon1 || !salon2)
     {
          cout<<"salonlardan biri bulunamadi"<<endl;
          return false;
     }

     return (*salon1 == *salon2); //== operatorunu kullanıldı
}

//kapasite altı salonlar
void sinemaSistemi::kapasiteAltiSalonlar(int kapasiteLimiti) const{
     cout<<kapasiteLimiti<<" den kucuk kapasiteye sahip salonlar: "<<endl;
     cout<<"-----------"<<endl;

     for (int i = 0; i < salonSayisi; i++)
     {
         if (*salonlar[i] <= sinemaSalonu("temp", kapasiteLimiti)){
               salonlar[i]->salonDetaylariGoster();
         }  
     } 
}

//kapasite ustu salonlar
void sinemaSistemi::kapasiteUstuSalonlar(int kapasiteLimiti) const{
     cout<<kapasiteLimiti<<" den buyuk kapasiteye sahip salonlar: "<<endl;
     cout<<"-----------"<<endl;

     for (int i = 0; i < salonSayisi; i++)
     {
         if (*salonlar[i] >= sinemaSalonu("temp", kapasiteLimiti)){
               salonlar[i]->salonDetaylariGoster();
         }  
     }
}

//film bulma fonksiyonu- normal versiyonu
Film* sinemaSistemi::getFilm(const string &filmAdi){
     for (int i = 0; i < filmSayisi; i++)
     {
          if (filmler[i]->getFilmAdi()==filmAdi)
          {
               return filmler[i];
          }
     }
     return nullptr; //filmi bulmzsa null döndürür
}

//film bulma fonksiyonu- const versiyonu
const Film* sinemaSistemi::getFilm(const string &filmAdi) const{
     for (int i = 0; i < filmSayisi; i++)
     {
          if (filmler[i]->getFilmAdi()==filmAdi)
          {
               return filmler[i];
          }
     }
     return nullptr; //filmi bulmzsa null döndürür
}

//film ekleme fonk
void sinemaSistemi::filmEkle(Film *film){
     for (int i = 0; i < filmSayisi; i++)
     {
          if (filmler[i]->getFilmAdi() == film->getFilmAdi())
          {
               cout<<"Bu film onceden eklenmistir"<<endl;
               return;
          }    
     }
     filmler[filmSayisi++]=film; 
     filmleriDosyayaYaz(); 
}

//film güncelleme fonksiyonu
void sinemaSistemi::filmGuncelle(const string &filmAdi, Film *yeniFilm){     
     bool filmGuncellendi=false;
     for (int i = 0; i < filmSayisi; i++)
     {
          if (filmler[i]->getFilmAdi()==filmAdi)
          {
               delete filmler[i];               
               filmler[i]= yeniFilm;
               filmGuncellendi=true;
          } 
     }
     if (filmGuncellendi)
     {
          cout<<"Film basariyla guncellendi "<<yeniFilm->getFilmAdi()<<endl;
          filmleriDosyayaYaz();
     }else{
          cout<<"Film bulunamadi"<<endl;
     }
}

//film silme fonk
void sinemaSistemi::filmSil(const string &filmAdi){
     for (int i = 0; i < filmSayisi; i++)
     {
          if (filmler[i]->getFilmAdi()==filmAdi)
          {
               delete filmler[i];

               //dizideki elemaları kaydırır boşluğu doldurmak için
               for (int j = i; j < filmSayisi-1; j++)
               {
                    filmler[j]=filmler[j+1];
               }

               filmSayisi--; //film sayısını bir azalt
               cout<<"film basariyla silindi, silinen filmin adi: "<<filmAdi<<endl;
               filmleriDosyayaYaz();
               return;
          } 
     }
     cout<<"film bulunamadi "<<endl;   
}

//film listesini yazdıran fonk
void sinemaSistemi::filmleriGoster() const{
     if (filmSayisi==0)
     {
          cout<<"sistemde kayitli film bulunamadi."<<endl;
          return;
     }
     for (int i = 0; i < filmSayisi; i++)
     {
          filmler[i]->filmDetaylariGoster();
     }
}

//salon ekleme fonk
void sinemaSistemi::salonEkle(sinemaSalonu *salon){
     if (salon==nullptr){
          cerr<<"Gecersiz salon"<<endl;
          return;
     }

     //aynı isime sahip salonları kontrol eder
     for (int i = 0; i < salonSayisi; i++)
     {
          if (salonlar[i]->getSalonAdi()==salon->getSalonAdi())
          {
               cout<<"Bu salon zaten kayitli"<<endl;
               return;
          } 
     }
     salonlar[salonSayisi++]=salon;
     salonlariDosyayaYaz();
}

//salon güncelleme işlemi
void sinemaSistemi::salonGuncelle(const string &salonAdi, sinemaSalonu *yeniSalon){
     bool salonGuncellendi=false;
     for (int i = 0; i < salonSayisi; i++)
     {
          if (salonlar[i]->getSalonAdi()==salonAdi)
          {
               delete salonlar[i];               
               salonlar[i]= yeniSalon;
               salonGuncellendi=true;
          } 
     }
     if (salonGuncellendi)
     {
          cout<<"salon basariyla guncellendi "<<yeniSalon->getSalonAdi()<<endl;
          salonlariDosyayaYaz();
     }else{
          cout<<"salon bulunamadi"<<endl;
     }
}

//salon silme fonk
void sinemaSistemi::salonSil(const string &salonAdi){
     for (int i = 0; i < salonSayisi; i++)
     {
          if (salonlar[i]->getSalonAdi()==salonAdi)
          {
               delete salonlar[i];

               for (int j = i; j < salonSayisi-1; j++)
               {
                    salonlar[j]=salonlar[j+1];
               }
               
               salonSayisi--;
               cout<<"salon basariyla silindi, silinen salon adi: "<<salonAdi<<endl;
               salonlariDosyayaYaz();
               return;
          }
     }
     cout<<"salon bulunamadi "<<endl;   
}

//salon bulma işlemi
sinemaSalonu* sinemaSistemi::getSalon(const string &salonAdi) const {
     for (int i = 0; i < salonSayisi; i++)
     {
          if (salonlar[i]->getSalonAdi() == salonAdi)
          {
               return salonlar[i];
          }   
     }
     return nullptr;// eğer salon bulunmazsa
}

//salon listesini yazdıran fonk
void sinemaSistemi::salonlariGoster() const{
     if (salonSayisi==0)
     {
          cout<<"sistemde kayitli salon bulunamadi."<<endl;
          return;
     }

     cout<<"Kayitli salonlar listesi: "<<endl;
     for (int i = 0; i < salonSayisi; i++)
     {
          salonlar[i]->salonDetaylariGoster();
     }
}

//seans ekleme fonk
void sinemaSistemi::seansEkle(const string &filmAdi, const string &seans){
     Film *film=getFilm(filmAdi);

     if (film==nullptr)
     {
          cout<<"film bulunamadi"<<endl;
          return;
     }
     film->seansEkle(seans);
     cout<<"seans basariyla eklendi, eklenen seans: "<<seans<<endl;
     filmleriDosyayaYaz();
}

//seans guncelleme fonk
void sinemaSistemi::seansGuncelle(const string &filmAdi, const string &eskiSeans, const string &yeniSeans){
     Film *film=getFilm(filmAdi);

     if (film==nullptr)
     {
          cout<<"film bulunamadi"<<endl;
          return;
     }

     film->seansSil(eskiSeans);
     film->seansEkle(yeniSeans);

     cout<<"seans basariyla guncellendi: "<<eskiSeans<<"-->"<<yeniSeans<<endl;
     filmleriDosyayaYaz();
}

//seans silme fonk
void sinemaSistemi::seansSil(const string &filmAdi, const string &seans){
     Film *film=getFilm(filmAdi);

     if (film==nullptr)
     {
          cout<<"film bulunamadi"<<endl;
          return;
     }

     film->seansSil(seans);
     cout<<"seans basariyla silindi"<<endl;
     filmleriDosyayaYaz();
}

//bilet işlemleri
//bileti kaydeden fonksiyon
void sinemaSistemi::biletKaydet(Bilet *bilet){
     if (biletSayisi>=100)
     {
          cerr<<"max bilet kapasitesine ulasildi"<<endl;
          return;
     }
     biletler[biletSayisi++]=bilet;
     biletleriDosyayaYaz();
}

//bilet satma fonksiyonu
void sinemaSistemi::biletSat(Musteri *musteri, Film *film, sinemaSalonu *salon, int koltukNo){
     if (salon->getBosKoltukSayisi() >0)
     {
          if (salon->koltukRezerveEt(1))
          {
               Bilet *yeniBilet=new Bilet(film, musteri,salon,koltukNo);
               biletKaydet(yeniBilet);
               cout<<"bilet satin alma islemi basarili"<<endl;
          }else{
               cout<<"bilet satin alma islemi basarisiz, koltuk bulunamadi"<<endl;
          }
     }else{
          cout<<"bilet satin alma islemi basarisiz, salon dolu"<<endl;
     }  
}

//biletleri listeleyen fonksiyon
void sinemaSistemi::biletleriListele() const{
     if (biletSayisi==0)
     {
          cout<<"hic bilet satin alinmadi"<<endl;
          return;
     }

     cout<<"\nSatilan Biletler Listesi\n";
     cout<<"-----------------------------\n";

     for (int i = 0; i < biletSayisi; i++)
     {
          cout<<"Film: "<<biletler[i]->getFilm()->getFilmAdi()<<endl;
          cout<<"Salon: "<<biletler[i]->getSalon()->getSalonAdi()<<endl;
          cout<<"Musteri: "<<biletler[i]->getMusteri()->getKullaniciAdi()<<" ("<< biletler[i]->getMusteri()->getMusteriTipi()<<" )"<<endl;
          cout<<"Koltuk No: "<<biletler[i]->getKoltukNo()<<endl;
          cout<<"-----------------------------\n";
     }  
}

//----------DOSYA İŞLEMLERİ----------------

//filmleri dosyaya yazma işlemi
void sinemaSistemi::filmleriDosyayaYaz() const{
     ofstream dosya("filmler.txt", ios::trunc); //dosyayı sıfırlar ve yeni verileri dosyaya yazar
     if (!dosya)
     {
          cout<<"Filmler dosyasi acilmadi"<<endl;
          return;
     }

     for (int i = 0; i < filmSayisi; i++)
     {
          dosya<<filmler[i]->getFilmAdi()<<","<<filmler[i]->getYasSiniri()<<","<<filmler[i]->getFilmSeanslari()<<endl;
     }
     dosya.close();  
}

//filmleri dosyadan okuma işlemi
void sinemaSistemi::filmleriDosyadanOku(){
     ifstream dosya("filmler.txt");
     if (!dosya)
     {
          cout<<"Filmler dosyasi bulunamadi"<<endl;
          return;
     }

     string filmAdi, filmSeansBilgisi;
     int yasSiniri;

     while (getline(dosya, filmAdi, ','))
     { 
          if (!(dosya>>yasSiniri))
          {
               cerr<<"Hata, yas siniri okunamadi"<<endl;
               break;
          }
          dosya.ignore();//virgülü atlar
          if (!getline(dosya, filmSeansBilgisi))
          {
               cerr<<"Hata, seans saati okunamadi"<<endl;
               break;
          }
          filmEkle(new Film(filmAdi, yasSiniri, filmSeansBilgisi));
     }
     dosya.close();  
}

//salonları dosyaya yazma işlmei
void sinemaSistemi::salonlariDosyayaYaz() const{
     ofstream dosya("salonlar.txt", ios::trunc);
     
     if (!dosya)
     {
          cout<<"salonlar.txt dosyasi acilmadi"<<endl;
          return;
     }
     
     if (salonSayisi==0)
     {
          cerr<<"hic salon eklnemedi, dosya bos"<<endl;
     }else{
          for (int i = 0; i < salonSayisi; i++)
          {
               dosya<< salonlar[i]->getSalonAdi()<<","<<salonlar[i]->getKapasite()<<endl;
          }
     }
     dosya.close();  
}

//salonları dosyadan okuma işlemi
void sinemaSistemi::salonlariDosyadanOku(){
     ifstream dosya("salonlar.txt");

     if (!dosya)
     {
          cerr<<"salonlar.txt dosyasi bulunamadi."<<endl;
          return;
     }

     string salonAdi;
     int kapasite;

     while (getline(dosya, salonAdi, ',') && dosya>>kapasite)
     {
          salonEkle(new sinemaSalonu(salonAdi, kapasite));
          dosya.ignore();
     }
     dosya.close();   
}

//biletleri dosyaya yaz
void sinemaSistemi::biletleriDosyayaYaz() const{
     ofstream dosya("biletler.txt", ios::trunc); //dosya sıfırlar

     if (!dosya)
     {
          cout<<"biletler.txt dosyasi acilmadi"<<endl;
          return;
     }

     for (int i = 0; i < biletSayisi; i++)
     {
          dosya<<biletler[i]->getFilm()->getFilmAdi()<<","<<biletler[i]->getSalon()->getSalonAdi()<<","<<biletler[i]->getMusteri()->getKullaniciAdi()<<","<<biletler[i]->getMusteri()->getMusteriTipi()<<","<<biletler[i]->getKoltukNo()<<endl;
     }
     dosya.close();
}

// //biletleri dosyadan oku
void sinemaSistemi::biletleriDosyadanOku(){
     ifstream dosya("biletler.txt");

     if (!dosya)
     {
          cerr<<"biletler.txt dosyasi bulunamadi"<<endl;
          return;
     }

     string filmAdi, salonAdi, musteriAdi, musteriTipi;
     int koltukNo;

     while (getline(dosya, filmAdi, ',') && getline(dosya, salonAdi, ',') && getline(dosya, musteriAdi, ',') && getline(dosya, musteriTipi, ',') && dosya>>koltukNo)
     {
          dosya.ignore();//satır sonu karakterini temizle

          //film ve salon bul
          Film *film= getFilm(filmAdi);
          sinemaSalonu *salon= getSalon(salonAdi);

          if (!film || !salon)
          {
               cerr<<"Film veya salon bulunamadi"<<endl;
               continue;
          }

          //musteri nesnesini olustur
          Musteri *musteri;
          if (musteriTipi=="ogrenci")
          {
               musteri=new Ogrenci(musteriAdi);
          }else{
               musteri=new TamBiletMusteri(musteriAdi);
          }
          
          Bilet *yeniBilet=new Bilet(film,musteri,salon,koltukNo);

          if (biletSayisi<100)
          {
               biletler[biletSayisi++]=yeniBilet;
          }else{
               cerr<<"bilet kapasitesi doldu"<<endl;
               delete yeniBilet;
          }
     }
     dosya.close();
}