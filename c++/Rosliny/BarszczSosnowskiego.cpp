#include <algorithm>
#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Point polozenie, Swiat* swiat) : Roslina(10, polozenie, swiat) {}

void BarszczSosnowskiego::akcja() {
    // Roslina::akcja();
    Point p[8] = { 
        Point(-1, -1), Point(-1, 0), Point(-1, 1), 
        Point(0, -1),               Point(0, 1), 
        Point(1, -1), Point(1, 0), Point(1, 1) 
    };
    for (int i = 0; i < 8; i++) {
        Organizm* organizmNaPlanszy = this->swiat->plansza[this->polozenie.y + p[i].y][this->polozenie.x + p[i].x];
        if (organizmNaPlanszy != nullptr) {
            this->swiat->plansza[this->polozenie.y + p[i].y][this->polozenie.x + p[i].x] = nullptr;
            auto it = std::find(this->swiat->organizmy.begin(), this->swiat->organizmy.end(), organizmNaPlanszy);
            *it = nullptr;
        }
    }
}

void BarszczSosnowskiego::kolizja(Organizm* inny) {
    this->swiat->plansza[inny->polozenie.y][inny->polozenie.x] = nullptr;
    auto it = std::find(this->swiat->organizmy.begin(), this->swiat->organizmy.end(), inny);
    *it = nullptr;
    auto it2 = std::find(this->swiat->organizmy.begin(), this->swiat->organizmy.end(), this);
    *it2 = nullptr;
}

char BarszczSosnowskiego::rysowanie() const {
    return 'B';
}

Organizm* BarszczSosnowskiego::clone() const {
    return new BarszczSosnowskiego(*this);
}