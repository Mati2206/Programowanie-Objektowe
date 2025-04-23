#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa(Point polozenie, Swiat* swiat); 
    char rysowanie() const override;
    Organizm* clone() const override;
    void akcja() override;
    void kolizja(Organizm* inny) override;
};