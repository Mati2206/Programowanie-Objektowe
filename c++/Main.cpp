#include <iostream>
#include "Swiat.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"

int main() {
    Swiat swiat = Swiat(20, 20);

    Organizm *czlowiek = new Czlowiek(Point(10, 10));
    swiat.organizmy.push_back(czlowiek);

    Organizm *wilk = new Wilk(Point(5, 5));
    swiat.organizmy.push_back(wilk);

    Organizm *owca = new Owca(Point(5, 10));
    swiat.organizmy.push_back(owca);

    char znak;
    while (true) {
        swiat.rysujSwiat();
        swiat.wykonajTure();
    }
    swiat.rysujSwiat();
    return 0;
}