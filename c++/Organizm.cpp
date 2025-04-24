#include <iostream>
#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, Point polozenie, Swiat* swiat) 
: sila(sila), inicjatywa(inicjatywa), polozenie(polozenie), wczesniejszePolozenie(polozenie), swiat(swiat) {}

Point Organizm::odbij(Point polozenie){
    if (polozenie.x < 0) polozenie.x = 0;
    if (polozenie.x >= swiat->getX()) polozenie.x = swiat->getX() - 1;
    if (polozenie.y < 0) polozenie.y = 0;
    if (polozenie.y >= swiat->getY()) polozenie.y = swiat->getY() - 1;
    return polozenie;
}

Point Organizm::nowePolozenie(Point orginalnePolozenie, int ile) {
    Point nowePolozenie = orginalnePolozenie;
        int r = rand() % 8;
        Point p[8] = {
            Point(-1, -1), Point(-1, 0), Point(-1, 1), 
            Point(0, -1),               Point(0, 1), 
            Point(1, -1), Point(1, 0), Point(1, 1) 
        };
        for (int i = 0; i < ile; i++) {
            if (r == 8) r = 0;
            if (nowePolozenie.y + p[r].y >= 0 && nowePolozenie.y + p[r].y < swiat->getY() && 
                nowePolozenie.x + p[r].x >= 0 && nowePolozenie.x + p[r].x < swiat->getX()) {
                nowePolozenie.x += p[r].x;
                nowePolozenie.y += p[r].y;
                break;
            }
            r++;
        }

        nowePolozenie = odbij(nowePolozenie);

    return nowePolozenie;
}

std::ostream& operator<<(std::ostream& os, const Organizm& organizm) {
    os << organizm.rysowanie();
    return os;
}

bool operator==(const Organizm& lhs, const Organizm& rhs) {
    return lhs.rysowanie() == rhs.rysowanie();
}

int Organizm::getSila() const {
    return sila;
}

int Organizm::getInicjatywa() const {
    return inicjatywa;
}

Point Organizm::getWczesniejszePolozenie() const {
    return wczesniejszePolozenie;
}

Point Organizm::getPolozenie() const {
    return polozenie;
}

Swiat* Organizm::getSwiat() const {
    return swiat;
}

void Organizm::setSila(int newSila) {
    sila = newSila;
}

void Organizm::setInicjatywa(int newInicjatywa) {
    inicjatywa = newInicjatywa;
}

void Organizm::setWczesniejszePolozenie(Point newWczesniejszePolozenie) {
    wczesniejszePolozenie = newWczesniejszePolozenie;
}

void Organizm::setPolozenie(Point newPolozenie) {
    polozenie = newPolozenie;
}

void Organizm::setPolozenie(int x, int y) { 
    polozenie.x = x;
    polozenie.y = y;
}

void Organizm::setSwiat(Swiat* newSwiat) {
    swiat = newSwiat;
}
