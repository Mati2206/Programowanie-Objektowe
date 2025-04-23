#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(Point polozenie, Swiat* swiat); 
    char znak() const override;
    Organizm* clone() const override;
};