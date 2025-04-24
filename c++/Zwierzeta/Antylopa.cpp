#include <algorithm>
#include "Antylopa.h"

Antylopa::Antylopa(Point polozenie, Swiat* swiat) : Zwierze(4, 4, polozenie, swiat) {}

char Antylopa::rysowanie() const { return 'A'; }

Organizm* Antylopa::clone() const {
    return new Antylopa(*this);
}

void Antylopa::akcja() {
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
    this->polozenie = this->nowePolozenie(this->polozenie, 2);
    Organizm* doKolizji = swiat->plansza[this->polozenie.y][this->polozenie.x];
    swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
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
    bool flag = 0;

    if (r) {
        this->swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
        for (int i = 0; i < 8; i++) {
            if (this->polozenie.y + p[i].y < 0 || this->polozenie.y + p[i].y >= this->swiat->y || 
                this->polozenie.x + p[i].x < 0 || this->polozenie.x + p[i].x >= this->swiat->x) {
                continue;
            }
            if (this->swiat->plansza[this->polozenie.y + p[i].y][this->polozenie.x + p[i].x] == nullptr) {
                this->polozenie = this->nowePolozenie(this->polozenie);
                flag = 1;
            }
        }
        this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
    }
    if (!flag) {
        Zwierze::kolizja(inny);
    }
}