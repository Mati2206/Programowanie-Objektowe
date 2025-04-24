#include "Lis.h"

Lis::Lis(Point polozenie, Swiat* swiat) : Zwierze(3, 7, polozenie, swiat) {}

char Lis::rysowanie() const { return 'L'; }

Organizm* Lis::clone() const {
    return new Lis(*this);
}

void Lis::akcja() {
    Point p[8] = { 
        Point(-1, -1), Point(-1, 0), Point(-1, 1), 
        Point(0, -1),               Point(0, 1), 
        Point(1, -1), Point(1, 0), Point(1, 1) 
    };
    int r = rand() % 8;
    this->setWczesniejszePolozenie(this->getPolozenie());
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), nullptr);
    for (int i = 0; i < 8; i++) {
        if (r == 8) r = 0;
        bool flag = 0;
        if (this->getPolozenie().y + p[r].y < 0 || this->getPolozenie().y + p[r].y >= getSwiat()->getY()  || 
            this->getPolozenie().x + p[r].x < 0 || this->getPolozenie().x + p[r].x >= getSwiat()->getX()) {
            r++;
            continue;
        }
        Organizm* naPlanszy = getSwiat()->getOrganizmNaPlanszy(this->getPolozenie().x + p[r].x, this->getPolozenie().y + p[r].y);

        if (naPlanszy == nullptr || naPlanszy->getSila() <= this->getSila()) {
            Point nowePolozenie = this->getPolozenie();
            nowePolozenie.x += p[r].x;
            nowePolozenie.y += p[r].y;
            this->setPolozenie(odbij(nowePolozenie));
            flag = 1;
        }

        if (flag) break;
        r++;
    }

    Organizm* doKolizji = this->getSwiat()->getOrganizmNaPlanszy(this->getPolozenie());
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), this);
    if (doKolizji != nullptr) {
        doKolizji->kolizja(this);
    }
}