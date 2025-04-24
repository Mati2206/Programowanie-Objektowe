#include <algorithm>
#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Point pozycja, Swiat* swiat) : Roslina(99, pozycja, swiat) {}

char WilczeJagody::rysowanie() const { return 'J'; }

void WilczeJagody::kolizja(Organizm* inny) {
    this->swiat->plansza[inny->polozenie.y][inny->polozenie.x] = nullptr;
    auto it = std::find(swiat->organizmy.begin(), swiat->organizmy.end(), inny);
    *it = nullptr; 
    auto it2 = std::find(swiat->organizmy.begin(), swiat->organizmy.end(), this);
    *it2 = nullptr; 
}

Organizm* WilczeJagody::clone() const {
    return new WilczeJagody(*this);
}