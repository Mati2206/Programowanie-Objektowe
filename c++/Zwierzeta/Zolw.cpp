#include "Zolw.h"

Zolw::Zolw(Point polozenie, Swiat* swiat) : Zwierze(2, 1, polozenie, swiat) {}

char Zolw::znak() const { return 'l'; }

Organizm* Zolw::clone() const {
    return new Zolw(*this);
}