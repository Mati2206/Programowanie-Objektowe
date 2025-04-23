// #include <conio.h>
#include "Czlowiek.h"

Czlowiek::Czlowiek(Point polozenie, Swiat* swiat) : Zwierze(5, 4, polozenie, swiat) {}

void Czlowiek::akcja(){
    int key;
    std::cin>>key;

    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
    switch (key) {
    case 0:
        this->polozenie.y -= 1;
        break;
    case 1:
        this->polozenie.y += 1;
        break;
    case 2:
        this->polozenie.x -= 1;
        break;
    case 3:
        this->polozenie.x += 1;
        break;
    }
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
}

char Czlowiek::znak() const { return 'c'; }

Organizm* Czlowiek::clone() const {
    return new Czlowiek(*this);
}