#pragma once
#include "Organizm.h"
#include <vector>

class Swiat {
private:
    int x;
    int y;
public:
    std::vector<Organizm> organizmy;

    Swiat(int x, int y);
    void wykonajTure();
    void rysujSwiat();
};