#pragma once
#include <iostream>

struct Point {
    int x;
    int y;
};

class Organizm {
public:
    std::string nazwa;
    int sila;
    int inicjatywa;
    Point polozenie;
    Organizm();
    Organizm(int sila, int inicjatywa, Point polozenie);

    void akcja();
    void kolizja();
    void rysowanie();
};