#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
    char znak() const override; 
    Zwierze(int sila, int inicjatywa, Point polozenie, Swiat* swiat);
    void akcja() override;
    void kolizja(Organizm* inny) override;
};