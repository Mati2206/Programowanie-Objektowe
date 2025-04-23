#include "Owca.h"

Owca::Owca(Point polozenie, Swiat* swiat)  : Zwierze(4, 4, polozenie, swiat) {}

char Owca::znak() const { return 'o'; }

Organizm* Owca::clone() const {
    return new Owca(*this);
}