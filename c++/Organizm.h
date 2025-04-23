#pragma once
#include <iostream>

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

class Organizm {
public:
    virtual char znak() const = 0;

    int sila;
    int inicjatywa;
    Point polozenie;
    Organizm();
    Organizm(int sila, int inicjatywa, Point polozenie);

    virtual void akcja() = 0;
    virtual void kolizja() = 0;
    void rysowanie();

    friend std::ostream& operator<<(std::ostream& os, const Organizm& organizm);
    friend bool operator==(const Organizm& lhs, const Organizm& rhs);
};