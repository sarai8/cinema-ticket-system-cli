/*
*@file kullanici.cpp
*@description - Kullanici sınıfının metodlarıyla kullanıcı ile alakalı işlemleri yapar
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include "../include/kullanici.h"
#include <iostream>
using namespace std;

//constructor
Kullanici::Kullanici(string ad): kullaniciAdi(ad){}

//getter metodu
string Kullanici::getKullaniciAdi() const{
     return kullaniciAdi;
}