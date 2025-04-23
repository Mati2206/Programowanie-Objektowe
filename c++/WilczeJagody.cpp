#include <algorithm>
#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Point pozycja, Swiat* swiat) : Roslina(99, pozycja, swiat) {}

char WilczeJagody::rysowanie() const { return 't'; }

void WilczeJagody::kolizja(Organizm* inny) {
    auto it = std::find(swiat->organizmy.begin(), swiat->organizmy.end(), inny);
    swiat->organizmy.erase(it);
    delete inny;
}