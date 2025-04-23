#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(Point polozenie); 
    char znak() const override;
};