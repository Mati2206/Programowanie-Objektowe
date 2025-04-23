#include "Antylopa.h"

Antylopa::Antylopa(Point polozenie, Swiat* swiat) : Zwierze(4, 4, polozenie, swiat) {}

char Antylopa::znak() const { return 'l'; }

Organizm* Antylopa::clone() const {
    return new Antylopa(*this);
}