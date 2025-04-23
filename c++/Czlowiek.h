#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
    Czlowiek(Point polozenie); 
    char znak() const override;
    void akcja() override;
};