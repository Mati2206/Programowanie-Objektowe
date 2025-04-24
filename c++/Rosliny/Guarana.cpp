#include "Guarana.h"

Guarana::Guarana(Point pozycja, Swiat* swiat) : Roslina(0, pozycja, swiat) {}

char Guarana::rysowanie() const { return 'G'; }

void Guarana::kolizja(Organizm* inny) {
    inny->sila += 3;
    Roslina::kolizja(inny);
}

Organizm* Guarana::clone() const {
    return new Guarana(*this);
}