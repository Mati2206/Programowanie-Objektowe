#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw(Point polozenie, Swiat* swiat); 
    char znak() const override;
    Organizm* clone() const override;
};