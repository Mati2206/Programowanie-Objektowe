#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
    Guarana(Point polozenie, Swiat* swiat);
    char rysowanie() const override;
    Organizm* clone() const override;
    void kolizja(Organizm* inny) override;
};