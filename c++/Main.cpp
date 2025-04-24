#include <iostream>
#include <algorithm>
#include "Swiat.h"
#include "Zwierzeta/Czlowiek.h"
#include "Zwierzeta/Wilk.h"
#include "Zwierzeta/Owca.h"
#include "Zwierzeta/Lis.h"
#include "Zwierzeta/Zolw.h"
#include "Zwierzeta/Antylopa.h"
#include "Rosliny/Trawa.h"
#include "Rosliny/Mlecz.h"
#include "Rosliny/Guarana.h"
#include "Rosliny/WilczeJagody.h"
#include "Rosliny/BarszczSosnowskiego.h"

int main() {
    Swiat swiat = Swiat(20, 20);

    Organizm *czlowiek = new Czlowiek(Point(10, 10), &swiat);
    swiat.dodajOrganizm(czlowiek);

    Organizm *wilk1 = new Wilk(Point(5, 5), &swiat);
    swiat.dodajOrganizm(wilk1);
    Organizm *wilk2 = new Wilk(Point(10, 5), &swiat);
    swiat.dodajOrganizm(wilk2);

    Organizm *owca1 = new Owca(Point(5, 10), &swiat);
    swiat.dodajOrganizm(owca1);
    Organizm *owca2 = new Owca(Point(10, 7), &swiat);
    swiat.dodajOrganizm(owca2);

    Organizm *lis1 = new Lis(Point(15, 15), &swiat);
    swiat.dodajOrganizm(lis1);
    Organizm *lis2 = new Lis(Point(18, 18), &swiat);
    swiat.dodajOrganizm(lis2);

    Organizm *zolw1 = new Zolw(Point(2, 2), &swiat);
    swiat.dodajOrganizm(zolw1);
    Organizm *zolw2 = new Zolw(Point(3, 3), &swiat);
    swiat.dodajOrganizm(zolw2);

    Organizm *antylopa1 = new Antylopa(Point(4, 4), &swiat);
    swiat.dodajOrganizm(antylopa1);
    Organizm *antylopa2 = new Antylopa(Point(6, 6), &swiat);
    swiat.dodajOrganizm(antylopa2);

    Organizm *trawa1 = new Trawa(Point(1, 1), &swiat);
    swiat.dodajOrganizm(trawa1);
    Organizm *trawa2 = new Trawa(Point(8, 8), &swiat);
    swiat.dodajOrganizm(trawa2);

    Organizm *mlecz1 = new Mlecz(Point(12, 12), &swiat);
    swiat.dodajOrganizm(mlecz1);
    Organizm *mlecz2 = new Mlecz(Point(15, 10), &swiat);
    swiat.dodajOrganizm(mlecz2);

    Organizm *guarana1 = new Guarana(Point(7, 7), &swiat);
    swiat.dodajOrganizm(guarana1);
    Organizm *guarana2 = new Guarana(Point(9, 9), &swiat);
    swiat.dodajOrganizm(guarana2);

    Organizm *wilczeJagody1 = new WilczeJagody(Point(11, 11), &swiat);
    swiat.dodajOrganizm(wilczeJagody1);

    Organizm* barszczSosnowskiego1 = new BarszczSosnowskiego(Point(2, 14), &swiat);
    swiat.dodajOrganizm(barszczSosnowskiego1);
    Organizm* barszczSosnowskiego2 = new BarszczSosnowskiego(Point(4, 16), &swiat);
    swiat.dodajOrganizm(barszczSosnowskiego2);

    while (true) {
        swiat.rysowanieSwiat();
        swiat.wykonajTure();
    }
    swiat.rysowanieSwiat();
    return 0;
}