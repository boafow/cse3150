//
//  ECMinesweeper.cpp
//  
//
//  Created by Yufeng Wu on 10/23/22.
//

#include "ECMinesweeper.h"
using namespace std;

// ****************************************************************
// Minesweeper class


// Constructor: nr (number of rows), nc (number of columns) in minesweeper field
ECMinesweeper :: ECMinesweeper(int nrIn, int ncIn) 
{
    // your code
}

ECMinesweeper :: ~ECMinesweeper()
{
}

// Set a position (x, y) in the field to a mine (x: x coordinate, y: y coordinate in the field)
// Note: each position can hold no more than one mine
void ECMinesweeper :: PlantMine(int x, int y)
{
    // your code
}

// Clear a mine from the field at position (x,y) if there is a mine at this position
void ECMinesweeper :: RemoveMine(int x, int y)
{
    // your code
}

// Get the mine number of a specific position (x,y). Mine number: number of mines in position (x,y) and adjacent (at most 8) positions
int ECMinesweeper :: GetMineNumber(int x, int y) const
{
    // your code
}
