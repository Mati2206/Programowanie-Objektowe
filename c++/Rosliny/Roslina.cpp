#include <algorithm>
#include "Roslina.h"

Roslina::Roslina(int sila, Point polozenie, Swiat* swiat) 
: Organizm(sila, 0, polozenie, swiat) {}

void Roslina::akcja() {
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
    int r = rand() % 30;
    if (r == 5) {
        Point nowePolozenie = this->nowePolozenie(this->polozenie);
        if (this->swiat->plansza[nowePolozenie.y][nowePolozenie.x] != nullptr) {
            return;
        }
        Organizm* potomek = this->clone();
        potomek->polozenie = nowePolozenie;
        swiat->dodajOrganizm(potomek);
    }
}

void Roslina::kolizja(Organizm* inny) {
    if (this->sila >= inny->sila) {
        this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
        auto it = std::find(this->swiat->organizmy.begin(), this->swiat->organizmy.end(), inny);
        *it = nullptr;
    } else {
        this->swiat->plansza[this->polozenie.y][this->polozenie.x] = inny;
        auto it = std::find(this->swiat->organizmy.begin(), this->swiat->organizmy.end(), this);
        *it = nullptr;
    }
}