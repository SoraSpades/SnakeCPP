#pragma once 
#include "pos.h"

// Screen dimensions
#define HEIGHT 20
#define WIDTH 60

// Struct to store the game board
struct Board {
    // Main board storage
    char board[HEIGHT][WIDTH];
    // Function to draw the board to the screen
    void drawBoard();
    // Function to get the char in a position p
    char getChar(Pos p);
    // Function to get the char in a position (x,y)
    char getChar(int x, int y);
    // Function to set the char c in a position p
    void setChar(Pos p, char c);
    // Function to set the char c in a position (x,y)
    void setChar(int x, int y, char c);
};