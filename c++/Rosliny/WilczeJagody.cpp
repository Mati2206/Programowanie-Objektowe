#include <algorithm>
#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Point pozycja, Swiat* swiat) : Roslina(99, pozycja, swiat) {}

char WilczeJagody::rysowanie() const { return 'J'; }

void WilczeJagody::kolizja(Organizm* inny) {
    this->getSwiat()->setOrganizmNaPlanszy(inny->getPolozenie(), nullptr);
    auto it = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), inny);
    *it = nullptr; 
    auto it2 = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), this);
    *it2 = nullptr; 
}

Organizm* WilczeJagody::clone() const {
    return new WilczeJagody(*this);
}