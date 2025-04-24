#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
    int szybkosc;
    int TuryAktywne;
    int TuryCoolDown;
public:
    Czlowiek(Point polozenie, Swiat* swiat); 
    char rysowanie() const override;
    Organizm* clone() const override;
    void akcja() override;
};