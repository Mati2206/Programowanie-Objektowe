#include "Roslina.h"

class Mlecz : Roslina {
public:
    Mlecz(Point polozenie, Swiat*);
    char znak() const override;
    void akcja() override;
};