#include "Roslina.h"

class WilczeJagody : Roslina {
public:
    WilczeJagody(Point polozenie, Swiat*);
    char znak() const override;
    void kolizja(Organizm* inny) override;
};