#include <iostream>
#include "Swiat.h"
#include "Organizm.h"

using namespace std;

Swiat::Swiat(int x, int y) {
    this->x = x;
    this->y = y;
}

void Swiat::rysujSwiat() {
    Organizm board[this->x][this->y] = { Organizm() };

    for (auto i : this->organizmy) {
        board[i.polozenie.x][i.polozenie.y] = i;
    }

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            string nazwa = board[i][j].nazwa;
            if (nazwa == "czlowiek") cout << 'c';
            else cout << '.';
        }
        cout << endl;
    }
}

void Swiat::wykonajTure() {
    for (auto i : this->organizmy) {

    }
}