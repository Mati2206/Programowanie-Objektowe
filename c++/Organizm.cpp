#include <iostream>
#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, Point polozenie, Swiat* swiat) 
: sila(sila), inicjatywa(inicjatywa), polozenie(polozenie), swiat(swiat) {}

Organizm::Organizm(int sila, Point polozenie, Swiat* swiat) 
: sila(sila), polozenie(polozenie), swiat(swiat) {}

Organizm::Organizm() 
: sila(0), inicjatywa(0), polozenie(0, 0) {}

Point Organizm::nowePolozenie(Point orginalnePolozenie) {
    Point nowePolozenie = orginalnePolozenie;
        int r = rand() % 8;
        switch (r) {
        case 0:
            nowePolozenie.y -= 1;
            break;
        case 1:
            nowePolozenie.x += 1;
            break;
        case 2: 
            nowePolozenie.y += 1;
            break;
        case 3: 
            nowePolozenie.x -= 1;
            break;
        case 4:
            nowePolozenie.y -= 1;
            nowePolozenie.x -= 1;
            break;
        case 5:
            nowePolozenie.y -= 1;
            nowePolozenie.x += 1;
            break;
        case 6:
            nowePolozenie.y += 1;
            nowePolozenie.x += 1;
            break;
        case 7:
            nowePolozenie.y += 1;
            nowePolozenie.x -= 1;
            break;
        }
    return nowePolozenie;
}

std::ostream& operator<<(std::ostream& os, const Organizm& organizm) {
    os << organizm.znak();
    return os;
}

bool operator==(const Organizm& lhs, const Organizm& rhs) {
    return lhs.znak() == rhs.znak();
}

