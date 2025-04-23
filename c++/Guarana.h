#pragma once
#include "Roslina.h"

class Guarana : Roslina {
public:
    Guarana(Point polozenie, Swiat* swiat);
    char znak() const override;
    void kolizja(Organizm* inny) override;
};