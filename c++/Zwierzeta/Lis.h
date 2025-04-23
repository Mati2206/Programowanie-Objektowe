#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
    Lis(Point polozenie, Swiat* swiat); 
    char rysowanie() const override;
    Organizm* clone() const override;
    void akcja() override;
};