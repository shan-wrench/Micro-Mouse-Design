#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "mouse.h"
#include "maze.h"

using namespace std;


// Constructor for the Cell class
Maze::Cell::Cell() : floodfillValue(-1) {
    // Initialize all walls to false (no walls by default)
    for (int i = 0; i < 4; i++) {
        walls[i] = false;
    }
}

// Method to get a reference to a specific cell in the maze
Maze::Cell& Maze::getCell(int x, int y) { 

    // Static dummy cell for out-of-bounds access
    static Cell dummyCell;

    if (x >= 0 && x < mazeWidth && y >= 0 && y < mazeWidth) {
        return cells[y][x];
    } else {
        return dummyCell;
    }
}

// Get cell (const version)
const Maze::Cell& Maze::getCell(int x, int y) const {
    return cells[y][x]; // Return const reference to Cell
}



// Method to set a wall in a given direction
void Maze::Cell::setWall(char direction, bool hasWall) {
    switch (direction) {
        case 'n': walls[0] = hasWall; break;  // Move north (up)
        case 'e': walls[1] = hasWall; break;  // Move south (down)
        case 's': walls[2] = hasWall; break; // Move east (right)
        case 'w': walls[3] = hasWall; break; // Move west (left)
        default: cout << "Invalid direction!" << endl; break;
    }
}   

// Method to check if a wall exists in a given direction
bool Maze::Cell::hasWall(char direction) const {
    switch (direction) {
        case 'n': return walls[0]; break;  // Move north (up)
        case 'e': return walls[1]; break;  // Move south (down)
        case 's': return walls[2]; break; // Move east (right)
        case 'w': return walls[3]; break; // Move west (left)
        default: return false; break;
    }
}

// Maze constructor
Maze::Maze(int MazeWidth, vector<pair<int, int>> goal)
    : mazeWidth(MazeWidth), goalCells(goal), cells(MazeWidth, vector<Cell>(MazeWidth)) {}

// Method to print the floodfill values of the maze
void Maze::printfloodFill() const {
    for (int i = mazeWidth-1; i > -1; i--) {
        for (int j = 0; j < mazeWidth; ++j) {
            cout << cells[i][j].floodfillValue << " ";
        }
        cout << endl;
    }
}

// Method to set the floodfill value for a specific cell
void Maze::setFloodfill(int x, int y, int value) {
    if (x >= 0 && x < mazeWidth && y >= 0 && y < mazeWidth) {
        getCell(x,y).floodfillValue = value;
    }
}

// Method to get the floodfill value of a specific cell
int Maze::getFloodfill(int x, int y) const {
    if (x >= 0 && x < mazeWidth && y >= 0 && y < mazeWidth) {
        return getCell(x,y).floodfillValue;
    }
    return -1; // Return -1 if the coordinates are out of bounds
}
