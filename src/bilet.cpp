/*
*@file bilet.cpp
*@description - Bilet sınıfının metodlarıyla bilet işlemleri yapar 
*@assignment - Bütünleme Projesi
*@date 08.02.2025
*@author Sara Ibrahim - sara.ibrahim@stu.fsm.edu.tr
*/
#include "../include/bilet.h"
#include "../include/film.h"
#include <iostream>
using namespace std;

//constructor
Bilet::Bilet(Film *film, Musteri *musteri, sinemaSalonu *salon, int kNo): film(film), musteri(musteri), salon(salon), koltukNo(kNo){}

Film* Bilet::getFilm() const{
     return film;
}

Musteri* Bilet::getMusteri() const{
     return musteri;
}

sinemaSalonu* Bilet::getSalon() const{
     return salon;
}

int Bilet::getKoltukNo() const{
     return koltukNo;
}