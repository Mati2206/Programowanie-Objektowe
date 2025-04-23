#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, Point polozenie) 
: Organizm(sila, inicjatywa, polozenie) {}


void Zwierze::akcja() {
    int gdzie = rand() % 4;

    switch (gdzie)
    {
    case 0:
        this->polozenie.y -= 1;
        break;
    case 1:
        this->polozenie.x += 1;
        break;
    case 2:
        this->polozenie.y += 1;
        break;
    case 3:
        this->polozenie.x -= 1;
        break;
    }
}

void Zwierze::kolizja() {
    
}