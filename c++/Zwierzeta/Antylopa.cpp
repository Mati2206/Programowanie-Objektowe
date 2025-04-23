#include "Antylopa.h"

Antylopa::Antylopa(Point polozenie, Swiat* swiat) : Zwierze(4, 4, polozenie, swiat) {}

char Antylopa::rysowanie() const { return 'l'; }

Organizm* Antylopa::clone() const {
    return new Antylopa(*this);
}

void Antylopa::akcja() {
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
    this->polozenie = this->nowePolozenie(this->polozenie, 2);
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
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
        for (int i = 0; i < 8; i++) {
            if (this->swiat->plansza[p[i].y][p[i].x] == nullptr) {
                this->polozenie = this->nowePolozenie(this->polozenie);
                flag = 1;
            }
        }
    }
}