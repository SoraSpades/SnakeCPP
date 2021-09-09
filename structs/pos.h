#pragma once 

// Struct to store a position
struct Pos {
    // X and Y parameters
    int x;
    int y;
    
    // Function to set a position by coordinates (x,y)
    void set(int newX, int newY);
    // Function to add two positions
    void add(int addX, int addY);
    // Function to add two positions
    void add(Pos p);
    // Function to multiply by int
    void multiply(int n);
    // Function to generate a random position
    void rnd();
    // Operator to check equality between positions
    inline bool operator==(Pos a) {
        return a.x==x && a.y==y;
    }
};