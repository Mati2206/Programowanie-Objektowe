#pragma once
#include <iostream>
#include "Swiat.h"

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Swiat;

class Organizm {
protected:
    Point nowePolozenie(Point oryginalnePolozenie);
public:
    virtual char znak() const = 0;
    virtual Organizm* clone() const = 0;

    int sila;
    int inicjatywa;
    Point polozenie;
    Swiat* swiat;
    Organizm();
    Organizm(int sila, int inicjatywa, Point polozenie, Swiat* swiat);
    Organizm(int sila, Point polozenie, Swiat* swiat);

    virtual void akcja() = 0;
    virtual void kolizja(Organizm* inny) = 0;
    void rysowanie();

    friend std::ostream& operator<<(std::ostream& os, const Organizm& organizm);
    friend bool operator==(const Organizm& lhs, const Organizm& rhs);
};