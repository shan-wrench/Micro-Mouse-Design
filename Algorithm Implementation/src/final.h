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

float readytoTurn(){
    float distance = 0;
    for(int i=0;i<=20;i++){
        distance = distance + sharp_c();
    }
    distance = distance/20;
    // Serial.print("Front ");
    // Serial.println(distance);

    float C_sharpError = 88 - distance;
        
    while(C_sharpError<0){
        float distance = 0;
        for(int i=0;i<=20;i++){
            distance = distance + sharp_c();
        }
        distance = distance/20;
        // Serial.print("Front ");
        // Serial.println(distance);
        C_sharpError = 88 - distance;
        encoderPid_turnready();
        forward();
    }
    brake();
    return distance;
}

bool wallFront() {
    float distance = 0;
    for(int i=0;i<=20;i++){
        distance = distance + sharp_c();
    }
    distance = distance/20;
    // Serial.print("Front ");
    // Serial.println(distance);
    if(distance > 150){
        Serial.print("front-false: ");
        Serial.println(distance);
        return false;
    }
    Serial.print("front-true: ");
    Serial.println(distance);
    return true;
}

bool wallRight() {
    float distance = shar_r_wall();
    // Serial.print("Right ");
    // Serial.println(distance);
    if(distance <= 250){
        Serial.print("right-false: ");
        Serial.println(distance);
        return false;
    }
    return true;
}

bool wallLeft() {
    float distance = shar_l_wall();
    // Serial.print("Left ");
    // Serial.println(distance);
    if(distance <= 500){
        Serial.print("left-false: ");
        Serial.println(distance);
        return false;
    }
    return true;
}

bool wallRight_frontsharp(){
    float distance = shar_l();
    // Serial.print("Left ");
    // Serial.println(distance);
    if(distance <= 250){
        Serial.print("left-false: ");
        Serial.println(distance);
        return false;
    }
    return true;
}

bool wallLeft_frontsharp(){
    float distance = shar_r();
    // Serial.print("Left ");
    // Serial.println(distance);
    if(distance <= 250){
        Serial.print("left-false: ");
        Serial.println(distance);
        return false;
    }
    return true;
}

void moveForward() {
    cellForward();
    brake();
    //delay(500);
}

void turnRight() {
    if(wallFront()){
        readytoTurn();
    }
    rightHalfTurn();
}

void turnLeft() {
    if(wallFront()){
        readytoTurn();
    }
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


