#include <iostream>
#include "Swiat.h"
#include "Czlowiek.h"

int main() {
    Swiat swiat = Swiat(20, 20);

    Point polozenie;
    polozenie.x = 10;
    polozenie.y = 10;
    Organizm czlowiek = Czlowiek(5, 4, polozenie);
    swiat.organizmy.push_back(czlowiek);

    swiat.rysujSwiat();
    return 0;
}