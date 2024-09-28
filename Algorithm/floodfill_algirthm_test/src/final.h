#include <cstdlib>
#include <iostream>

using namespace std;



int mazeWidth() {
    std::cout << "mazeWidth" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

int mazeHeight() {
    std::cout << "mazeHeight" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

int readytoTurn(){
    int C_sharpValue = 0;
        for(int i=0; i<2; i++){
            C_sharpValue = C_sharpValue + analogRead(sharpc);
        }
        C_sharpValue = C_sharpValue/2;
        int C_sharpError = 620 - C_sharpValue;
        
    while(C_sharpError>0){
        for(int i=0; i<2; i++){
            C_sharpValue = C_sharpValue + analogRead(sharpc);
        }
        C_sharpValue = C_sharpValue/2;
        C_sharpError = 620 - C_sharpValue;
        encoderPid_turnready();
        forward();
    }
    delay(100);
    brake();
    return C_sharpValue;
}

bool wallFront() {
    float distance = sharp_c();
    if(distance <= 120){
        return true;
    }
    return false;
}

bool wallRight() {
    float distance = shar_r();
    if(distance <= 120){
        return false;
    }
    return true;
}

bool wallLeft() {
    float distance = shar_l();
    if(distance <= 120){
        return false;
    }
    return true;
}

void moveForward() {
    cellForward();
    brake();
    delay(500);
}

void turnRight() {
    readytoTurn();
    rightHalfTurn();
}

void turnLeft() {
    readytoTurn();
    leftHalfTurn();
}

void setWall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

void clearWall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

void setColor(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

void clearColor(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
}

void clearAllColor() {
    std::cout << "clearAllColor" << std::endl;
}

void setText(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

void clearText(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
}

void clearAllText() {
    std::cout << "clearAllText" << std::endl;
}

bool wasReset() {
    std::cout << "wasReset" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

void ackReset() {
    std::cout << "ackReset" << std::endl;
    std::string ack;
    std::cin >> ack;
}


