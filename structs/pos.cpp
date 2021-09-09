#include "board.h"
#include <stdlib.h>
#include <time.h>

void Pos::set(int newX, int newY) { 
    x = newX; 
    y = newY; 
};
void Pos::add(int addX, int addY) {
    x += addX;
    y += addY;
};
void Pos::add(Pos p) {
    x += p.x;
    y += p.y;
}
void Pos::multiply(int n) {
    x *= n;
    y *= n;
}
void Pos::rnd() {
    srand(time(0));
    x = rand() % (WIDTH - 10) + 5;
    y = rand() % (HEIGHT -10) + 5;
};