#include "Roslina.h"

class Trawa : Roslina {
public:
    Trawa(Point polozenie, Swiat*);
    char znak() const override;
};