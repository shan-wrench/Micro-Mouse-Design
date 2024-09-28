#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Maze {
  public:
    Maze(int MazeWidth, vector<pair<int,int>> goal)
        : mazeWidth(MazeWidth), goalCells(goal), floodfill(MazeWidth, vector<int>(MazeWidth, -1)) {
    }

    void floodfillAlgorithm() {
        // Initialize BFS queue
        queue<pair<int, int>> q;

        for(const auto& goal : goalCells) {
            q.push(goal); // Push goal cells to the queue
            floodfill[goal.first][goal.second] = 0; // Distance from goal is 0
        }

        // Directions for movement (right, left, down, up)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (isValid({nx, ny}) && floodfill[nx][ny] == -1) {
                    floodfill[nx][ny] = floodfill[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    void printMazeWidth() const {
        cout << "Maze Width: " << mazeWidth << endl;
    }

    void printFloodfillMatrix() const {
        for (const auto& row : floodfill) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

  private:
    bool isValid(pair<int, int> position) const {
        return (position.first >= 0 && position.first < mazeWidth && position.second >= 0 && position.second < mazeWidth);
    }

    vector<vector<int>> floodfill;
    int mazeWidth;
    vector<pair<int,int>> goalCells;
};

int main() {
    // Create a maze object
    vector<pair<int,int>> goal = {{0,0}, {1,0}, {1,1}};
    Maze myMaze(16, goal);
    myMaze.floodfillAlgorithm();
    myMaze.printMazeWidth();
    myMaze.printFloodfillMatrix(); // Print the floodfill matrix to see the results
}
