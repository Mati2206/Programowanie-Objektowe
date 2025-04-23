#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
public:
    Owca(Point polozenie); 
    char znak() const override;
};