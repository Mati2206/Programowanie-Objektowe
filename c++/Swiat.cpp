#include <iostream>
#include "Swiat.h"
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
            switch (board[i][j].nazwa) {

                case "czlowiek":
                    cout << 'c';
                    break;
                default:
                    cout << ' ';
                    break;
            }
            cout << '.';
        }
        cout << endl;
    }
}

void Swiat::wykonajTure() {
    for (auto i : this->organizmy) {

    }
}