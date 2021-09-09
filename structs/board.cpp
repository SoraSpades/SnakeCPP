#include "board.h"
#include <iostream>

using namespace std;

// Gets the char in position p
char Board::getChar(Pos p) {
    return board[p.y][p.x];
}
// Gets the char in position (x, y)
char Board::getChar(int x, int y) {
    return board[y][x];
}

// Sets char c in position p
void Board::setChar(Pos p, char c) {
    board[p.y][p.x] = c;
}
// Sets char c in position (x, y)
void Board::setChar(int x, int y, char c) {
    board[y][x] = c;
}

// Draws the global board variable on screen
void Board::drawBoard() {
    system("cls");
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0 ; i < WIDTH ; i++) {
            cout << board[j][i];
        }
        cout << endl;
    }
}