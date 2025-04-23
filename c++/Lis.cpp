#include "Lis.h"

Lis::Lis(Point polozenie, Swiat* swiat) : Zwierze(9, 5, polozenie, swiat) {}

char Lis::znak() const { return 'l'; }

Organizm* Lis::clone() const {
    return new Lis(*this);
}