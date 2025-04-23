#include "Trawa.h"

Trawa::Trawa(Point pozycja, Swiat* swiat) : Roslina(0, pozycja, swiat) {}

char Trawa::znak() const { return 't'; }