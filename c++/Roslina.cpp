#include "Roslina.h"

Roslina::Roslina(int sila, Point polozenie, Swiat* swiat) 
: Organizm(sila, 0, polozenie, swiat) {}

void Roslina::akcja() {
    int r = rand() % 10;
    if (r == 1) {
        Point nowePolozenie = this->nowePolozenie(this->polozenie);
        Organizm* potomek = this->clone();
        potomek->polozenie = nowePolozenie;
        swiat->organizmy.push_back(potomek);
    }
}
