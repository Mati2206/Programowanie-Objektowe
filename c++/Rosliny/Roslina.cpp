#include <algorithm>
#include "Roslina.h"

Roslina::Roslina(int sila, Point polozenie, Swiat* swiat) 
: Organizm(sila, 0, polozenie, swiat) {}

void Roslina::akcja() {
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
    int r = rand() % 30;
    if (r == 5) {
        Point nowePolozenie = this->nowePolozenie(this->getPolozenie());
        if (this->getSwiat()->getOrganizmNaPlanszy(nowePolozenie) != nullptr) {
            return;
        }
        Organizm* potomek = this->clone();
        potomek->setPolozenie(nowePolozenie);
        this->getSwiat()->dodajOrganizm(potomek);
    }
}

void Roslina::kolizja(Organizm* inny) {
    if (this->getSila() >= inny->getSila()) {
        this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
        auto it = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), inny);
        *it = nullptr;
    } else {
        this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), inny);
        auto it = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), this);
        *it = nullptr;
    }
}