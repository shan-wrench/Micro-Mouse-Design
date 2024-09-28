#pragma once
#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <utility>


using namespace std;

class Maze {
public:
    // Nested Cell class
    class Cell {
    public:
        bool walls[4];  // 0 - North, 1 - East, 2 - South, 3 - West
        int floodfillValue; // Floodfill value for each cell

        // Constructor for Cell class (declared here, implemented in .cpp)
        Cell();

        // Method to set a wall in a given direction
        void setWall(char direction, bool hasWall);

        // Method to check if a wall exists in a given direction
        bool hasWall(char direction) const;
    };

    // Constructor for Maze class (declared here, implemented in .cpp)
    Maze(int MazeWidth, vector<pair<int, int>> goal);

    // Method to print the maze's floodfill values
    void printfloodFill() const;

    // Method to set floodfill value for a specific cell
    void setFloodfill(int x, int y, int value);

    // Method to get floodfill value of a specific cell
    int getFloodfill(int x, int y) const;

    Cell& getCell(int x, int y);               // Non-const version (modifiable)
    const Cell& getCell(int x, int y) const; // Const version


    int mazeWidth; // Width of the maze
    vector<vector<Cell>> cells; // 2D vector of cells
    vector<pair<int, int>> goalCells; // Vector to store goal positions

private:
    // Any additional private methods or members can go here
};

#endif // MAZE_H
