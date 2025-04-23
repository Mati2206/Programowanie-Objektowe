#include <iostream>
#include "Swiat.h"
#include "Organizm.h"

using namespace std;

Swiat::Swiat(int x, int y) {
    this->x = x;
    this->y = y;
    this->plansza = new Organizm**[y];
    for (int i = 0; i < y; i++) {
        this->plansza[i] = new Organizm*[x];
    }
}

void Swiat::rysujSwiat() {
    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            if (this->plansza[i][j] == nullptr) {
                cout << '.';
                continue;
            }
            cout << *this->plansza[i][j];
        }
        cout << endl;
    }
}

void Swiat::wykonajTure() {
    auto organizmy_kopia = this->organizmy;

    for (Organizm* org : organizmy_kopia) {
        org->akcja();
    }
}

void Swiat::dodajOrganizm(Organizm* org) {
    this->organizmy.push_back(org);
    this->plansza[org->polozenie.y][org->polozenie.x] = org;
}