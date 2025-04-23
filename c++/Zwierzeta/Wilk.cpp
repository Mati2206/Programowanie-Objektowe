#include "Wilk.h"

Wilk::Wilk(Point polozenie, Swiat* swiat) : Zwierze(9, 5, polozenie, swiat) {}

char Wilk::rysowanie() const { return 'w'; }

Organizm* Wilk::clone() const {
    return new Wilk(*this);
}