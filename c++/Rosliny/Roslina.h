#pragma once
#include "../Organizm.h"

class Roslina : public Organizm {
public:
    Roslina(int sila, Point polozenie, Swiat* swiat);
    void akcja() override;
    void kolizja(Organizm* inny) override;
};