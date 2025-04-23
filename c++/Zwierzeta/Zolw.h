#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw(Point polozenie, Swiat* swiat); 
    char rysowanie() const override;
    Organizm* clone() const override;
    void akcja() override;
    void kolizja(Organizm* inny) override;
};