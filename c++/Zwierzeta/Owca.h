#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
public:
    Owca(Point polozenie, Swiat* swiat); 
    char znak() const override;
    Organizm* clone() const override;
};