#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, Point polozenie, Swiat* swiat) 
: Organizm(sila, inicjatywa, polozenie, swiat) {}

void Zwierze::akcja() {
    int gdzie = rand() % 4;

    switch (gdzie)
    {
    case 0:
        this->polozenie.y -= 1;
        break;
    case 1:
        this->polozenie.x += 1;
        break;
    case 2:
        this->polozenie.y += 1;
        break;
    case 3:
        this->polozenie.x -= 1;
        break;
    }
}

char Zwierze::znak() const { return 'z';}

void Zwierze::kolizja(Organizm* inny) {
    std::cout << "ELOO" << std::endl;
    if (*this == *inny) {
        Point nowePolozenie = this->polozenie;
        int r = rand() % 4;
        switch (r) {
        case 0:
            nowePolozenie.y -= 1;
            break;
        case 1:
            nowePolozenie.x += 1;
            break;
        case 2: 
            nowePolozenie.y += 1;
            break;
        case 3: 
            nowePolozenie.x -= 1;
            break;
        }

        std::cout << "siemano" << std::endl;
        Organizm* potomek = this->clone();
        potomek->polozenie = nowePolozenie;
        swiat->organizmy.push_back(potomek);
    }
}