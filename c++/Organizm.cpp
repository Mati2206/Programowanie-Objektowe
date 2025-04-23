#include <iostream>
#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, Point polozenie) 
: sila(sila), inicjatywa(inicjatywa), polozenie(polozenie) {}

Organizm::Organizm() 
: sila(0), inicjatywa(0), polozenie(0, 0) {}

std::ostream& operator<<(std::ostream& os, const Organizm& organizm) {
    os << organizm.znak();
    return os;
}

bool operator==(const Organizm& lhs, const Organizm& rhs) {
    return lhs.znak() == rhs.znak();
}