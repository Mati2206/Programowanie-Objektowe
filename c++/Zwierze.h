#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
    Zwierze(int sila, int inicjatywa, Point polozenie);
    void akcja() override;
    void kolizja() override;
};