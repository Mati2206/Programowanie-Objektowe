#include "Roslina.h"

class WilczeJagody : Roslina {
public:
    WilczeJagody(Point polozenie, Swiat*);
    char rysowanie() const override;
    void kolizja(Organizm* inny) override;
};