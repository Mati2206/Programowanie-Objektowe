#include "Lis.h"

Lis::Lis(Point polozenie, Swiat* swiat) : Zwierze(3, 7, polozenie, swiat) {}

char Lis::rysowanie() const { return 'l'; }

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
    this->wczesniejszePolozenie = this->polozenie;
    swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
    for (int i = 0; i < 8; i++) {
        if (r == 8) r = 0;
        bool flag = 0;
        if (swiat->plansza[this->polozenie.y + p[r].y][this->polozenie.x + p[r].x] == nullptr
         || swiat->plansza[this->polozenie.y + p[r].y][this->polozenie.x + p[r].x]->sila <= this->sila){
            this->polozenie.x += p[r].x;
            this->polozenie.y += p[r].y;
            flag = 1;
        }
        if (flag) break;
        r++;
    }
    swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
}