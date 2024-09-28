#pragma once
#ifndef MOUSE_H
#define MOUSE_H

#include <utility> // For std::pair
#include <map>     // For std::map
#include <string>  // For std::string

class Mouse {
public:
    char direction;
    std::pair<int, int> position;

    // Constructor
    Mouse(char direction, std::pair<int, int> position);

    // Map directions to vectors using string keys
    std::map<std::string, std::pair<int, int>> directionMap;

    void moveForward();
    void rotateLeft();
    void rotateRight();

private:
};

#endif // MOUSE_H
