#include <iostream>
#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, Point polozenie) {
    this->sila = sila;
    this->inicjatywa = inicjatywa;
    this->polozenie = polozenie;
}

Organizm::Organizm() {
    this->sila = 0;
    this->inicjatywa = 0;
    Point p;
    p.x = 0;
    p.y = 0; 
    this->polozenie = p;
}