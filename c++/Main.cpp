#include <iostream>
#include "Swiat.cpp"
#include "Czlowiek.cpp"

int main() {
    Swiat swiat = Swiat(20, 20);

    Organizm czlowiek = Czlowiek(5, 4, Point(10, 10));
    swiat.organizmy.push_back(czlowiek);

    swiat.rysujSwiat();
    return 0;
}