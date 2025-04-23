#include "Owca.h"

Owca::Owca(Point polozenie) : Zwierze(4, 4, polozenie) {}

char Owca::znak() const { return 'o'; }