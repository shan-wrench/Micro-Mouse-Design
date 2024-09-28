// #include "API.h"
// #include <cstdlib>
// #include <iostream>

// #include <Pins.h>
// #include <s.h>
// #include <sharp.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <Display.h>
// #include <Variables.h>
// #include <ZlgoVariables.h>
// #include <Motors.h>
// #include <Turns.h>
// #include <Tof.h>
// #include <WallPid.h>
// #include <Speed.h>
// #include <Moves.h>

// using namespace std;



// int API::mazeWidth() {
//     std::cout << "mazeWidth" << std::endl;
//     std::string response;
//     std::cin >> response;
//     return atoi(response.c_str());
// }

// int API::mazeHeight() {
//     std::cout << "mazeHeight" << std::endl;
//     std::string response;
//     std::cin >> response;
//     return atoi(response.c_str());
// }

// bool API::wallFront() {
//     float distance = sharp_c();
//     if(distance <= 120){
//         return true;
//     }
//     return false;
// }

// bool API::wallRight() {
//     float distance = shar_r();
//     if(distance <= 120){
//         return true;
//     }
//     return false;
// }

// bool API::wallLeft() {
//     float distance = shar_l();
//     if(distance <= 120){
//         return true;
//     }
//     return false;
// }

// void API::moveForward(int distance) {
//     cellForward();
// }

// void API::turnRight() {
//     rightHalfTurn();
// }

// void API::turnLeft() {
//     leftHalfTurn();
// }

// void API::setWall(int x, int y, char direction) {
//     std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
// }

// void API::clearWall(int x, int y, char direction) {
//     std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
// }

// void API::setColor(int x, int y, char color) {
//     std::cout << "setColor " << x << " " << y << " " << color << std::endl;
// }

// void API::clearColor(int x, int y) {
//     std::cout << "clearColor " << x << " " << y << std::endl;
// }

// void API::clearAllColor() {
//     std::cout << "clearAllColor" << std::endl;
// }

// void API::setText(int x, int y, const std::string& text) {
//     std::cout << "setText " << x << " " << y << " " << text << std::endl;
// }

// void API::clearText(int x, int y) {
//     std::cout << "clearText " << x << " " << y << std::endl;
// }

// void API::clearAllText() {
//     std::cout << "clearAllText" << std::endl;
// }

// bool API::wasReset() {
//     std::cout << "wasReset" << std::endl;
//     std::string response;
//     std::cin >> response;
//     return response == "true";
// }

// void API::ackReset() {
//     std::cout << "ackReset" << std::endl;
//     std::string ack;
//     std::cin >> ack;
// }
