#pragma once
#include <vector>
#include "Organizm.h"

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