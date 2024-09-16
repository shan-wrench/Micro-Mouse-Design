#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <utility>

using namespace std;

class Maze {
public:
    // Constructor to initialize the maze with width and goal cells
    Maze(int MazeWidth, vector<pair<int, int>> goal);

    // Method to apply the floodfill algorithm
    void floodfillAlgorithm();

    // Method to print the maze width
    void printMazeWidth() const;

private:
    int mazeWidth; // Width of the maze
    vector<vector<int>> floodfill; // 2D vector for floodfill distances
    vector<pair<int, int>> goalCells; // Vector to store goal positions

    // Check if a position is valid within maze bounds
    bool isValid(pair<int, int> next_position) const;
};

#endif // MAZE_H
