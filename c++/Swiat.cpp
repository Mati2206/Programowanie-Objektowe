#include <algorithm>
#include <iostream>
#include "Swiat.h"
#include "Organizm.h"

using namespace std;

Swiat::Swiat(int x, int y) : x(x), y(y) { 
    this->tura = 0;
    this->plansza = new Organizm**[y];
    for (int i = 0; i < y; i++) {
        this->plansza[i] = new Organizm*[x];
        for (int j = 0; j < x; j++) {
            this->plansza[i][j] = nullptr;
        }
    }
}

void Swiat::rysowanieSwiat() {
    Organizm* czlowiek = nullptr;
    for (int i = 0; i < this->organizmy.size(); i++) {
        if (this->organizmy[i] != nullptr && this->organizmy[i]->rysowanie() == 'C') {
            czlowiek = this->organizmy[i];
            break;
        }
    }
    if (czlowiek == nullptr) {
        cout << "Nie ma czlowieka na planszy!" << endl;
        return;
    }
    cout << "Tura: " << this->tura 
         << " Czlowiek: (" << czlowiek->getPolozenie().x 
         << ", " << czlowiek->getPolozenie().y 
         << ") Siła: " << czlowiek->getSila() << endl;
    for (int i = 0; i < this->y; i++) {
        for (int j = 0; j < this->x; j++) {
            if (this->plansza[i][j] == nullptr)
                cout << '.';
            else
                cout << this->plansza[i][j]->rysowanie();
        }
        cout << endl;
    }
}

void Swiat::wykonajTure() {
    this->tura++;
    std::sort(this->organizmy.begin(), this->organizmy.end(), [](Organizm* a, Organizm* b) { return a->getInicjatywa() > b->getInicjatywa(); });
    for (int i = 0; i < this->organizmy.size(); i++) {
        if (this->organizmy[i] == nullptr) continue;
        this->organizmy[i]->akcja();
    }
    for (auto it = this->organizmy.begin(); it != this->organizmy.end(); ) {
        if (*it == nullptr) {
            it = this->organizmy.erase(it);
        } else {
            it++;
        }
    }
}

void Swiat::dodajOrganizm(Organizm* org) {
    this->organizmy.push_back(org);
    this->plansza[org->getPolozenie().y][org->getPolozenie().x] = org;
}

int Swiat::getX() const {
    return this->x;
}

int Swiat::getY() const {
    return this->y;
}

int Swiat::getTura() const {
    return this->tura;
}

Organizm* Swiat::getOrganizmNaPlanszy(int x, int y) const {
    if (x >= 0 && x < this->x && y >= 0 && y < this->y) {
        return this->plansza[y][x];
    } else {
        cout << "Nieprawidłowe współrzędne (" << x << ", " << y << ")!" << endl;
        return nullptr;
    }
}

Organizm* Swiat::getOrganizmNaPlanszy(Point punkt) const {
    return Swiat::getOrganizmNaPlanszy(punkt.x, punkt.y);
}

const std::vector<Organizm*>& Swiat::getOrganizmy() const {
    return this->organizmy;
}

void Swiat::setX(int x) {
    this->x = x;
}

void Swiat::setY(int y) {
    this->y = y;
}

void Swiat::setTura(int tura) {
    this->tura = tura;
}

void Swiat::setOrganizmNaPlanszy(Point punkt, Organizm* organizm) {
    int x = punkt.x;
    int y = punkt.y;
    if (x >= 0 && x < this->x && y >= 0 && y < this->y) {
        this->plansza[y][x] = organizm;
        if (organizm != nullptr) {
            organizm->setPolozenie({x, y});
        }
    } else {
        cout << "Nieprawidłowe współrzędne (" << x << ", " << y << ")!" << endl;
    }
}


void Swiat::setOrganizmy(const std::vector<Organizm*>& organizmy) {
    this->organizmy = organizmy;
}