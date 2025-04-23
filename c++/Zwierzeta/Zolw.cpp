#include "Zolw.h"

Zolw::Zolw(Point polozenie, Swiat* swiat) : Zwierze(2, 1, polozenie, swiat) {}

char Zolw::rysowanie() const { return 'l'; }

Organizm* Zolw::clone() const {
    return new Zolw(*this);
}

void Zolw::akcja() {
    int r = rand() % 4;
    if (r == 1) {
        Zwierze::akcja();
    }
}

void Zolw::kolizja(Organizm* inny) {
    Zwierze::kolizja(inny);
    if (inny->sila < 5) inny->polozenie = inny->wczesniejszePolozenie;
}