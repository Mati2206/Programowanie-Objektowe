#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
    Lis(Point polozenie, Swiat* swiat); 
    char znak() const override;
    Organizm* clone() const override;
};