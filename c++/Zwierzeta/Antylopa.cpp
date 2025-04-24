#include <algorithm>
#include "Antylopa.h"

Antylopa::Antylopa(Point polozenie, Swiat* swiat) : Zwierze(4, 4, polozenie, swiat) {}

char Antylopa::rysowanie() const { return 'A'; }

Organizm* Antylopa::clone() const {
    return new Antylopa(*this);
}

void Antylopa::akcja() {
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), nullptr);
    this->setPolozenie(this->nowePolozenie(this->getPolozenie(), 2));
    Organizm* doKolizji = this->getSwiat()->getOrganizmNaPlanszy(this->getPolozenie());
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
    if (doKolizji != nullptr) {
        doKolizji->kolizja(this);
    }
}

void Antylopa::kolizja(Organizm* inny) {
    Point p[8] = { 
        Point(-1, -1), Point(-1, 0), Point(-1, 1), 
        Point(0, -1),               Point(0, 1), 
        Point(1, -1), Point(1, 0), Point(1, 1) 
    };
    int r = rand() % 2;
    bool flag = false;

    if (r) {
        this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), nullptr);
        for (int i = 0; i < 8; i++) {
            int newY = this->getPolozenie().y + p[i].y;
            int newX = this->getPolozenie().x + p[i].x;
            if (newY < 0 || newY >= this->getSwiat()->getY() || 
                newX < 0 || newX >= this->getSwiat()->getX()) {
                continue;
            }
            if (this->getSwiat()->getOrganizmNaPlanszy(newX, newY) == nullptr) {
                this->setPolozenie(newX, newY);
                flag = true;
                break;
            }
        }
        this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
    }
    if (!flag) {
        Zwierze::kolizja(inny);
    }
}