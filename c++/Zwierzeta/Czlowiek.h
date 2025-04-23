#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
    Czlowiek(Point polozenie, Swiat* swiat); 
    char rysowanie() const override;
    Organizm* clone() const override;
    void akcja() override;
};