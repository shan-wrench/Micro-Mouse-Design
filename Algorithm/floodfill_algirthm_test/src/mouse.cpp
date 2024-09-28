#include <iostream>
#include <vector>
#include <map>
#include "mouse.h"

using namespace std; 

Mouse::Mouse(char direction, pair<int,int> position):direction(direction),position(position){}

// Move forward function definition
void Mouse::moveForward() {
    // Move based on the current direction
    switch (direction) {
        case 'n': position.second++; break;  // Move north (up)
        case 's': position.second--; break;  // Move south (down)
        case 'e': position.first++; break; // Move east (right)
        case 'w': position.first--; break; // Move west (left)
        default: cout << "Invalid direction!" << endl; break;
    }
}

void Mouse::rotateLeft() {
        // Rotate counter-clockwise
        switch (direction) {
            case 'n': direction = 'w'; break;
            case 's': direction = 'e'; break;
            case 'e': direction = 'n'; break;
            case 'w': direction = 's'; break;
        }
        cout << "Mouse rotated left. Now facing: " << direction << endl;
}

void Mouse::rotateRight() {
        // Rotate clockwise
        switch (direction) {
            case 'n': direction = 'e'; break;
            case 's': direction = 'w'; break;
            case 'e': direction = 's'; break;
            case 'w': direction = 'n'; break;
        }
        cout << "Mouse rotated right. Now facing: " << direction << endl;
}

