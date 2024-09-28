#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "floodfill.h"
#include "mouse.h"
#include "maze.h"
#include <algorithm>  // For std::find

using namespace std;

void floodfillAlgorithm(Maze& maze) {

        // Reset the floodfill values of all cells to -1 (unvisited)
    for (int x = 0; x < maze.mazeWidth; ++x) {
        for (int y = 0; y < maze.mazeWidth; ++y) {
            maze.getCell(x, y).floodfillValue = -1;  // Reset each cell
        }
    }

    
    // Initialize BFS queue
    queue<pair<int, int>> q;

    // Push goal cells into the queue and set their floodfill value to 0
    for (const auto& goal : maze.goalCells) {
        q.push(goal);  // Push goal cells to the Queue
        maze.getCell(goal.first,goal.second).floodfillValue = 0;  // Distance from goal is 0
    }

    // Define the isValid function inside floodfillAlgorithm
    auto isValid = [&](pair<int, int> next_position) {
        return (next_position.first >= 0 && next_position.first < maze.mazeWidth &&
                next_position.second >= 0 && next_position.second < maze.mazeWidth);
    };

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1} , {-1,0}};  // Directions: North, east, South, WEST
    vector<char> directionz = {'n', 'e', 's', 'w'};

    

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < directions.size(); i++) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;           


            // Check if the new position is valid and not blocked by a wall
            if (isValid({nx, ny}) && !maze.getCell(x,y).hasWall(directionz[i])){
                // Use std::find to check if the element is in the vector
               if (maze.getCell(nx, ny).floodfillValue == -1) {
                    maze.getCell(nx, ny).floodfillValue = maze.getCell(x, y).floodfillValue + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
