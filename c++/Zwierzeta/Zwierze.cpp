#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, Point polozenie, Swiat* swiat) 
: Organizm(sila, inicjatywa, polozenie, swiat) {}

void Zwierze::akcja() {
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
    this->wczesniejszePolozenie = this->polozenie;
    this->polozenie = this->nowePolozenie(this->polozenie);
    if (this->swiat->plansza[this->polozenie.y][this->polozenie.x] != nullptr) {
        this->swiat->plansza[this->polozenie.y][this->polozenie.x]->kolizja(this);
    }
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
}

void Zwierze::kolizja(Organizm* inny) {
    if (*this == *inny) {
        Point nowePolozenie = this->nowePolozenie(this->polozenie);
        Organizm* potomek = this->clone();
        potomek->polozenie = nowePolozenie;
        swiat->organizmy.push_back(potomek);
    }
}