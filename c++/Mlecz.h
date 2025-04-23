#include "Roslina.h"

class Mlecz : Roslina {
public:
    Mlecz(Point polozenie, Swiat*);
    char rysowanie() const override;
    void akcja() override;
};