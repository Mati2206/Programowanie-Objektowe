#include <iostream>
#include <algorithm>
#include "Swiat.h"
#include "Zwierzeta/Czlowiek.h"
#include "Zwierzeta/Wilk.h"
#include "Zwierzeta/Owca.h"

int main() {
    Swiat swiat = Swiat(20, 20);

    Organizm *czlowiek = new Czlowiek(Point(10, 10), &swiat);
    swiat.dodajOrganizm(czlowiek);

    Organizm *wilk1 = new Wilk(Point(5, 5), &swiat);
    swiat.dodajOrganizm(wilk1);
    Organizm *wilk2 = new Wilk(Point(10, 5), &swiat);
    swiat.dodajOrganizm(wilk2);
    Organizm *wilk3 = new Wilk(Point(7, 5), &swiat);
    swiat.dodajOrganizm(wilk3);

    Organizm *owca = new Owca(Point(5, 10), &swiat);
    swiat.dodajOrganizm(owca);

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