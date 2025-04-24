#include "Roslina.h"

class WilczeJagody : public Roslina {
public:
    WilczeJagody(Point polozenie, Swiat*);
    char rysowanie() const override;
    Organizm* clone() const override;
    void kolizja(Organizm* inny) override;
};