#pragma once
#include "Organizm.h"
#include <vector>

class Organizm;

class Swiat {
private:
    int x;
    int y;
    int tura;
    Organizm*** plansza;
    std::vector<Organizm*> organizmy;

public:
    Swiat(int x, int y);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    int getTura() const;
    void setTura(int tura);

    Organizm* getOrganizmNaPlanszy(int x, int y) const;
    void setOrganizmNaPlanszy(int x, int y, Organizm* org);

    const std::vector<Organizm*>& getOrganizmy() const;
    void setOrganizmy(const std::vector<Organizm*>& organizmy);

    void dodajOrganizm(Organizm* org);
    void wykonajTure();
    void rysowanieSwiat();
};