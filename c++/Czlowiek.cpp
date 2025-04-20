#include "Czlowiek.h"

Czlowiek::Czlowiek(int sila, int inicjatywa, Point polozenie) 
: Zwierze(sila, inicjatywa, polozenie) {
    this->nazwa = "czlowiek";
}