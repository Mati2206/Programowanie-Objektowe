#include <iostream>
#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, Point polozenie, Swiat* swiat) 
: sila(sila), inicjatywa(inicjatywa), polozenie(polozenie), wczesniejszePolozenie(polozenie), swiat(swiat) {}

Point Organizm::nowePolozenie(Point orginalnePolozenie, int ile=1) {
    Point nowePolozenie = orginalnePolozenie;
        int r = rand() % 8;
        switch (r) {
        case 0:
            nowePolozenie.y -= ile;
            break;
        case 1:
            nowePolozenie.x += ile;
            break;
        case 2: 
            nowePolozenie.y += ile;
            break;
        case 3: 
            nowePolozenie.x -= ile;
            break;
        case 4:
            nowePolozenie.y -= ile;
            nowePolozenie.x -= ile;
            break;
        case 5:
            nowePolozenie.y -= ile;
            nowePolozenie.x += ile;
            break;
        case 6:
            nowePolozenie.y += ile;
            nowePolozenie.x += ile;
            break;
        case 7:
            nowePolozenie.y += ile;
            nowePolozenie.x -= ile;
            break;
        }
    return nowePolozenie;
}

std::ostream& operator<<(std::ostream& os, const Organizm& organizm) {
    os << organizm.rysowanie();
    return os;
}

bool operator==(const Organizm& lhs, const Organizm& rhs) {
    return lhs.rysowanie() == rhs.rysowanie();
}

