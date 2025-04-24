#include "Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(Point polozenie, Swiat*);
    Organizm* clone() const override;
    char rysowanie() const override;
    void akcja() override;
};