#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa(Point polozenie, Swiat* swiat); 
    char znak() const override;
    Organizm* clone() const override;
};