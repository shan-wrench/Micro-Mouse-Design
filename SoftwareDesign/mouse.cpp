#include <iostream>
#include <vector>
#include <map>

using namespace std; 

class Mouse{
    public:
    Mouse(pair<int,int> direction, pair<int,int> position){
    }
    
    // Map directions to vectors using string keys
    map<string, pair<int, int>> directionMap = {
        {"N", {0, 1}}, // North
        {"S", {0, -1}},  // South
        {"W", {-1, 0}}, // West
        {"E", {1, 0}}   // East
    };

    private:
}; 