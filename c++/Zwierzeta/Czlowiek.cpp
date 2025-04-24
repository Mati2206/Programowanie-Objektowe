#include <conio.h>
#include "Czlowiek.h"
#include <parallel/compatibility.h>

Czlowiek::Czlowiek(Point polozenie, Swiat* swiat) : Zwierze(5, 4, polozenie, swiat) {
    this->szybkosc = 1;
    this->TuryAktywne = 0;
    this->TuryCoolDown = 0;
}

void Czlowiek::akcja() {
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
    this->wczesniejszePolozenie = this->polozenie;
    int key = _getch();
    if (key == 224 || key == 0) {
        key = _getch();
        switch (key) {
        case 72:
            this->polozenie.y -= this->szybkosc;
            break;
        case 80:
            this->polozenie.y += this->szybkosc;
            break;
        case 75:
            this->polozenie.x -= this->szybkosc;
            break;
        case 77:
            this->polozenie.x += this->szybkosc;
            break;
        default:
            break;
        }
    }
    if (key == ' ') {
        if (this->TuryCoolDown == 0 && this->TuryAktywne == 0) {
            this->TuryAktywne = 6;
            this->TuryCoolDown = 11;
        }
    }
    if (this->TuryCoolDown > 0) {
        this->TuryCoolDown--;
    } 
    if (this->TuryAktywne > 2) {
        this->TuryAktywne--;
        this->szybkosc = 2;
    } 
    else if (this->TuryAktywne > 0) {
        this->TuryAktywne--;
        int r = rand() % 2;
        if (r) {
            this->szybkosc = 2;
        } else {
            this->szybkosc = 1;
        }
    } else {
        this->szybkosc = 1;
    }

    this->polozenie = this->odbij(this->polozenie);
    Organizm* organizmNaPlanszy = this->swiat->plansza[this->polozenie.y][this->polozenie.x];
    if (organizmNaPlanszy != nullptr) {
        organizmNaPlanszy->kolizja(this);
    }
    this->swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
}

char Czlowiek::rysowanie() const { return 'C'; }

Organizm* Czlowiek::clone() const {
    return new Czlowiek(*this);
}