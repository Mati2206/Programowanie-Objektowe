#include "Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
    BarszczSosnowskiego(Point polozenie, Swiat* swiat);
    Organizm* clone() const override;
    void akcja() override; 
    void kolizja(Organizm* inny) override; 
    char rysowanie() const override;
};