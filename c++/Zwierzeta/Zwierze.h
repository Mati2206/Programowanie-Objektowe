#pragma once
#include "../Organizm.h"

class Zwierze : public Organizm {
protected:
    Zwierze(int sila, int inicjatywa, Point polozenie, Swiat* swiat);
    void akcja() override;
    void kolizja(Organizm* inny) override;
};