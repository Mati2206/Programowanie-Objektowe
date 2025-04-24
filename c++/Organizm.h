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
private:
    int sila;
    int inicjatywa;
    Point wczesniejszePolozenie;
    Point polozenie;
    Swiat* swiat;

protected:
    Point nowePolozenie(Point oryginalnePolozenie, int ile = 1);
    Point odbij(Point polozenie);

public:
    Organizm(int sila, int inicjatywa, Point polozenie, Swiat* swiat);

    virtual char rysowanie() const = 0;
    virtual Organizm* clone() const = 0;
    virtual void akcja() = 0;
    virtual void kolizja(Organizm* inny) = 0;

    int getSila() const;
    int getInicjatywa() const;
    Point getWczesniejszePolozenie() const;
    Point getPolozenie() const;
    Swiat* getSwiat() const;

    void setSila(int newSila);
    void setInicjatywa(int newInicjatywa);
    void setWczesniejszePolozenie(Point newWczesniejszePolozenie);
    void setPolozenie(Point newPolozenie);
    void setSwiat(Swiat* newSwiat);

    friend std::ostream& operator<<(std::ostream& os, const Organizm& organizm);
    friend bool operator==(const Organizm& lhs, const Organizm& rhs);
};