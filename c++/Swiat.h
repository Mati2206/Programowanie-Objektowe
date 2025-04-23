#pragma once
#include "Organizm.h"
#include <vector>

class Organizm;

class Swiat {
private:
    int x;
    int y;
public:
    Organizm*** plansza;
    std::vector<Organizm*> organizmy;

    void dodajOrganizm(Organizm* org);
    Swiat(int x, int y);
    void wykonajTure();
    void rysowanieSwiat();
};