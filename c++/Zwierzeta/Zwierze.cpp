#include <algorithm>
#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, Point polozenie, Swiat* swiat) 
: Organizm(sila, inicjatywa, polozenie, swiat) {}

void Zwierze::akcja() {
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie().y, this->getPolozenie().x, nullptr);
    this->setWczesniejszePolozenie(this->getPolozenie());
    this->setPolozenie(this->nowePolozenie(this->getPolozenie()));
    Organizm* doKolizji = this->getSwiat()->getOrganizmNaPlanszy(this->getPolozenie().y, this->getPolozenie().x);
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie().y, this->getPolozenie().x, this);
    if (doKolizji != nullptr) {
        doKolizji->kolizja(this);
    }
}

void Zwierze::kolizja(Organizm* inny) {
    if (*this == *inny) {
        this->polozenie = this->wczesniejszePolozenie;
        Point nowePolozenie = this->nowePolozenie(this->polozenie);
        Organizm* potomek = this->clone();
        potomek->polozenie = nowePolozenie;
        this->swiat->dodajOrganizm(potomek);
    }
    else {
        if (this->sila >= inny->sila) {
            this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
            auto it = std::find(this->swiat->organizmy.begin(), this->swiat->organizmy.end(), inny);
            *it = nullptr;
        }
        else {
            this->swiat->plansza[this->polozenie.y][this->polozenie.x] = inny;
            auto it = std::find(this->swiat->organizmy.begin(), this->swiat->organizmy.end(), this);
            *it = nullptr;
        }
    }
}