#include <iostream>
#include "Swiat.h"
#include "Organizm.h"

using namespace std;

Swiat::Swiat(int x, int y) {
    this->x = x;
    this->y = y;
}

void Swiat::rysujSwiat() {
    Organizm* board[this->x][this->y] = {};

    for (int i = 0; i < this->organizmy.size(); i++) {
        Organizm* org = this->organizmy[i];
        board[org->polozenie.y][org->polozenie.x] = org;
    }

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            if (board[i][j] == nullptr) {
                cout << '.';
                continue;
            }
            cout << *board[i][j];
        }
        cout << endl;
    }
}

void Swiat::wykonajTure() {
    for (int i = 0; i < this->organizmy.size(); i++) {
        this->organizmy[i]->akcja();
    }
}