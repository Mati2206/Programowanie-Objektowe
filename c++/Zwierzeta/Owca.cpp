#include "Owca.h"

Owca::Owca(Point polozenie, Swiat* swiat)  : Zwierze(4, 4, polozenie, swiat) {}

char Owca::rysowanie() const { return 'O'; }

Organizm* Owca::clone() const {
    return new Owca(*this);
}