#include "Mlecz.h"

Mlecz::Mlecz(Point pozycja, Swiat* swiat) : Roslina(0, pozycja, swiat) {}

char Mlecz::rysowanie() const { return 'M'; }

void Mlecz::akcja() { 
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
    for (int i = 0; i < 3; i++) {
        Roslina::akcja();
    }
} 

Organizm* Mlecz::clone() const {
    return new Mlecz(*this);
}