#include "Guarana.h"

Guarana::Guarana(Point pozycja, Swiat* swiat) : Roslina(0, pozycja, swiat) {}

char Guarana::znak() const { return 'g'; }

void Guarana::kolizja(Organizm* inny) {
    inny->sila += 3;
}