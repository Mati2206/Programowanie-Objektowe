#include <iostream>
#include <algorithm>
#include "Swiat.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"

int main() {
    Swiat swiat = Swiat(20, 20);

    Organizm *czlowiek = new Czlowiek(Point(10, 10), &swiat);
    swiat.organizmy.push_back(czlowiek);

    Organizm *wilk1 = new Wilk(Point(5, 5), &swiat);
    swiat.organizmy.push_back(wilk1);
    Organizm *wilk2 = new Wilk(Point(10, 5), &swiat);
    swiat.organizmy.push_back(wilk2);

    Organizm *owca = new Owca(Point(5, 10), &swiat);
    swiat.organizmy.push_back(owca);

    sort(swiat.organizmy.begin(), swiat.organizmy.end(), [](Organizm* a, Organizm* b) {
        return a->inicjatywa > b->inicjatywa;
    });

    char znak;
    while (true) {
        swiat.rysujSwiat();
        swiat.wykonajTure();
    }
    swiat.rysujSwiat();
    return 0;
}