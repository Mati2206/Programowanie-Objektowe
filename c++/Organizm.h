#pragma once
#include "Swiat.h"

class Point {
public:
    int x;
    int y;
    Point(int x, int y) { this->x = x; this->y = y; }
};

class Organizm {
public:
    char nazwa[50];
    int sila;
    int inicjatywa;
    Point polozenie;
    Organizm();
    Organizm(int sila, int inicjatywa, Point polozenie);

    void akcja();
    void kolizja();
    void rysowanie();
};