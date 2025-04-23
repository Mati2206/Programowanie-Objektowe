#include "Lis.h"

Lis::Lis(Point polozenie, Swiat* swiat) : Zwierze(3, 7, polozenie, swiat) {}

char Lis::znak() const { return 'l'; }

Organizm* Lis::clone() const {
    return new Lis(*this);
}

void Lis::akcja() {
    int r = rand() % 8;
    for (int i = 0; i < 8; i++) {
        if (r == 8) r = 0;
        bool flag = 0;
        switch (r) {
        case 0:
            if (swiat->plansza[this->polozenie.y - 1][this->polozenie.x - 1] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.x--; this->polozenie.y--;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        case 1:
            if (swiat->plansza[this->polozenie.y - 1][this->polozenie.x] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.y--;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        case 2:
            if (swiat->plansza[this->polozenie.y - 1][this->polozenie.x + 1] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.x++; this->polozenie.y--;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        case 3:
            if (swiat->plansza[this->polozenie.y][this->polozenie.x - 1] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.x--;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        case 4:
            if (swiat->plansza[this->polozenie.y][this->polozenie.x + 1] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.x++;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        case 5:
            if (swiat->plansza[this->polozenie.y + 1][this->polozenie.x - 1] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.x--; this->polozenie.y++;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        case 6:
            if (swiat->plansza[this->polozenie.y + 1][this->polozenie.x] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.y++;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        case 7:
            if (swiat->plansza[this->polozenie.y + 1][this->polozenie.x + 1] == nullptr) {
                swiat->plansza[this->polozenie.y][this->polozenie.x] = nullptr;
                this->polozenie.x++; this->polozenie.y++;
                swiat->plansza[this->polozenie.y][this->polozenie.x] = this;
                flag = 1;
            }
            break;
        }
        if (flag) break;
        r++;
    }
}