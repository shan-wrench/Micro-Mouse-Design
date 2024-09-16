#include <iostream>
#include <string>
#include "mouse.h"
#include "maze.h"
#include "API.h"

using namespace std;

void log(const string& text) {
    cerr << text << endl;
}

int main(int argc, char* argv[]) {
    log("Running...");
    API::setColor(0, 0, 'G');
    API::setText(0, 0, "abc");
    while (true) {
        if (!API::wallLeft()) {
            API::turnLeft();
        }
        while (API::wallFront()) {
            API::turnRight();
        }
        API::moveForward();
    }
}
