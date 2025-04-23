#pragma once
#include "Roslina.h"

class Guarana : Roslina {
public:
    Guarana(Point polozenie, Swiat* swiat);
    char rysowanie() const override;
    void kolizja(Organizm* inny) override;
};