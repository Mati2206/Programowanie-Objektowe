#include <algorithm>
#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, Point polozenie, Swiat* swiat) 
: Organizm(sila, inicjatywa, polozenie, swiat) {}

void Zwierze::akcja() {
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), nullptr);
    this->setWczesniejszePolozenie(this->getPolozenie());
    this->setPolozenie(this->nowePolozenie(this->getPolozenie()));
    Organizm* doKolizji = this->getSwiat()->getOrganizmNaPlanszy(this->getPolozenie());
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
    if (doKolizji != nullptr) {
        doKolizji->kolizja(this);
    }
}

void Zwierze::kolizja(Organizm* inny) {
    if (*this == *inny) {
        this->setPolozenie(this->getWczesniejszePolozenie());
        Point nowePolozenie = this->nowePolozenie(this->getPolozenie());
        Organizm* potomek = this->clone();
        potomek->setPolozenie(nowePolozenie);
        this->getSwiat()->dodajOrganizm(potomek);
    }
    else {
        if (this->getSila() >= inny->getSila()) {
            this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
            auto it = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), inny);
            *it = nullptr;
        }
        else {
            this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), inny);
            auto it = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), this);
            *it = nullptr;
        }
    }
}