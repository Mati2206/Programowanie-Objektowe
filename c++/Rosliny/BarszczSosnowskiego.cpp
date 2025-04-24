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
        Organizm* organizmNaPlanszy = this->getSwiat()->getOrganizmNaPlanszy(this->getPolozenie().x + p[i].x, this->getPolozenie().y + p[i].y);
        if (organizmNaPlanszy != nullptr) {
            this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), nullptr);
            auto it = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), organizmNaPlanszy);
            *it = nullptr;
        }
    }
}

void BarszczSosnowskiego::kolizja(Organizm* inny) {
    this->getSwiat()->setOrganizmNaPlanszy(this->getPolozenie(), nullptr);
    auto it = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), inny);
    *it = nullptr;
    auto it2 = std::find(this->getSwiat()->organizmy.begin(), this->getSwiat()->organizmy.end(), this);
    *it2 = nullptr;
}

char BarszczSosnowskiego::rysowanie() const {
    return 'B';
}

Organizm* BarszczSosnowskiego::clone() const {
    return new BarszczSosnowskiego(*this);
}