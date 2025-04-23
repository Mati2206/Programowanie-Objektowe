#include <conio.h>
#include "Czlowiek.h"

Czlowiek::Czlowiek(Point polozenie, Swiat* swiat) : Zwierze(5, 4, polozenie, swiat) {}

void Czlowiek::akcja(){
    int key = _getch();
    key = _getch();

    switch (key) {
    case 72:
        this->polozenie.y -= 1;
        break;
    case 80:
        this->polozenie.y += 1;
        break;
    case 75:
        this->polozenie.x -= 1;
        break;
    case 77:
        this->polozenie.x += 1;
        break;
    }
}

char Czlowiek::znak() const { return 'c'; }

Organizm* Czlowiek::clone() const {
    return new Czlowiek(*this);
}