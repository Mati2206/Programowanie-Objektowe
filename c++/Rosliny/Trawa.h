#include "Roslina.h"

class Trawa : public Roslina {
public:
    Trawa(Point polozenie, Swiat*);
    Organizm* clone() const override;
    char rysowanie() const override;
};