//
//  ECMinesweeper.h
//  
//
//  Created by Yufeng Wu on 10/23/22.
//

#ifndef ECMinesweeper_h
#define ECMinesweeper_h


// ****************************************************************
// Minesweeper class

class ECMinesweeper
{
public:
    // Constructor: nr (number of rows), nc (number of columns) in minesweeper field
    ECMinesweeper(int nr, int nc);
    virtual ~ECMinesweeper();
    
    // Set a position (x, y) in the field to a mine (x: x coordinate, y: y coordinate in the field)
    // coordinates: 0-based
    // Note: each position can hold no more than one mine
    // You can assume x and y wont' cause out-of-bound
    void PlantMine(int x, int y);
    
    // Clear a mine from the field at position (x,y) if there is a mine at this position
    // You can assume x and y wont' cause out-of-bound
    void RemoveMine(int x, int y);
    
    // Get the mine number of a specific position (x,y). Mine number: number of mines in position (x,y) and adjacent (at most 8) positions
    // You can assume x and y wont' cause out-of-bound
    int GetMineNumber(int x, int y) const;
    
private:
    // your code
};

#endif /* ECMinesweeper_h */
