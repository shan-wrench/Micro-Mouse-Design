#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;


class Maze {     // The class
  public:           // Access specifier
    Maze(int MazeWidth, vector<pair<int,int>> goal):mazeWidth(MazeWidth),goalCells(goal),floodfill(MazeWidth, vector<int>(MazeWidth, -1)){
    }

    void floodfillAlgorithm(){
        // Initialize BFS queue
        queue<pair<int, int>> q;

        for(const auto& goal : goalCells){
            q.push(goal); //Push goal cells to the Queue
            floodfill[goal.first][goal.second] = 0; // Distance from goal is 0
        }
    }

    // Method to print the maze width
    void printMazeWidth() const {
        for (const auto& cell : goalCells) {
        }
    }

   private:
   int mazeWidth;
   // Directions for movement (right, left, down, up)
   vector<vector<int>> floodfill;
   vector<pair<int,int>> goalCells;

   bool isValid(pair<int, int> next_position){
            return ((next_position.first<mazeWidth && next_position.second<mazeWidth) && (next_position.first>=0 && next_position.second>=0));
        }

};

int main(){
    //Create a maze obj
    vector<pair<int,int>> goal={{0,0},{1,0},{1,1}};
    Maze myMaze(16,goal);
    myMaze.printMazeWidth();
}
