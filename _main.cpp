#include <iostream>
#include <windows.h>
#include "structs/board.h"
#include "structs/pos.h"

using namespace std;

// Game status
bool gameOver;
int score = 0;
float timeFrame = 100; //ms
const float speedUp = 2; //ms

// Characters for drawing
char borderChar = '#';
char headChar   = '@';
char bodyChar   = '$';
char fruitChar  = '*';
char emptyChar  = '.';

// Game board
Board board;

// Positions
Pos headPos;
Pos fruitPos; 
Pos nextMove;

void setup() {

    // Game status init
    gameOver = false;

    // Setup positions
    headPos.set((int)(WIDTH / 2),(int)(HEIGHT / 2));
    do { // Avoid fruit appearing in the head position
        fruitPos.rnd();
    } while (fruitPos == headPos);

    // Setup game board
    for (size_t j = 0; j < HEIGHT; j++){
    for (size_t i = 0; i < WIDTH ; i++){
        if (i == 0 || j == 0 || i == WIDTH - 1 || j == HEIGHT - 1 ) board.setChar(i,j,borderChar);
        else board.setChar(i,j,emptyChar); 
    }}
    
    // Draw head and fruit
    board.setChar(headPos, headChar);
    board.setChar(fruitPos, fruitChar);
}

void logic() {
    system("cls");
    if (GetAsyncKeyState(VK_UP)) {
        nextMove.set(0, -1);
    }
    if (GetAsyncKeyState(VK_LEFT)) {
        nextMove.set(-1, 0);
    }
    if (GetAsyncKeyState(VK_DOWN)) {
        nextMove.set(0, 1);
    }
    if (GetAsyncKeyState(VK_RIGHT)) {
        nextMove.set(1, 0);
    }
    board.setChar(headPos, bodyChar);
    headPos.add(nextMove);

    if (board.getChar(headPos) == borderChar || board.getChar(headPos) == bodyChar) {
        gameOver = true;
    } else {
        if (board.getChar(headPos) == fruitChar) {
            score++;
            timeFrame -= speedUp;
            do {
                fruitPos.rnd();
            } while (board.getChar(fruitPos) == headChar || board.getChar(fruitPos) == bodyChar);
            board.setChar(fruitPos, fruitChar);
        }
        board.setChar(headPos, headChar);
        // Body management
    }
    
}

int main() {
    setup();
    while (!gameOver) {
        logic();
        board.drawBoard();
        Sleep(timeFrame);
    }
    return 0;
}