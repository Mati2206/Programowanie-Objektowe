#include "Czlowiek.h"

Czlowiek::Czlowiek(Point polozenie) : Zwierze(5, 4, polozenie) {}

void Czlowiek::akcja(){
    char znak;
    std::cin >> znak;
    switch (znak) {
    case 'w':
        this->polozenie.y -= 1;
        break;
    case 's':
        this->polozenie.y += 1;
        break;
    case 'a':
        this->polozenie.x -= 1;
        break;
    case 'd':
        this->polozenie.x += 1;
        break;
    }
}

char Czlowiek::znak() const { return 'c'; }