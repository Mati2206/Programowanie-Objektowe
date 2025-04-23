#include "Mlecz.h"

Mlecz::Mlecz(Point pozycja, Swiat* swiat) : Roslina(0, pozycja, swiat) {}

char Mlecz::znak() const { return 'm'; }

void Mlecz::akcja() { 
    for (int i = 0; i < 3; i++) {
        Roslina::akcja();
    }
} 