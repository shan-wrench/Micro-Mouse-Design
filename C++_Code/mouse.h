#ifndef MOUSE_H
#define MOUSE_H

#include <utility> // For std::pair
#include <map> // For std::map>
#include <string> // For std::string>

using namespace std;

class Mouse {
public:
    // Constructor
    Mouse(pair<int, int> direction, pair<int, int> position);

private:
    // Map directions to vectors using string keys
    map<string, pair<int, int>> directionMap;
};

#endif // MOUSE_H
