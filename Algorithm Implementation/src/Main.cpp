#include <Arduino.h>
#include <iostream>
#include <vector>
#include <string>
#include "mouse.h"
#include "maze.h"
#include "floodfill.h"
#include <limits> // for std::numeric_limits

#include <Pins.h>
#include <s.h>
#include <sharp.h>
#include <Wire.h>
#include <Variables.h>
#include <ZlgoVariables.h>
#include <Motors.h>
#include <Turns.h>
#include <Tof.h>
#include <WallPid.h>
#include <Speed.h>

void cellAlign();
void wallFollower2();
void wallFollower_singleWall();

//Car
void cellAdjust();

bool fastrun = false;
#include <Moves.h>

#include <final.h>

bool check = 0;
bool precheck=0;

float previous_lefterror = 0;
float previous_rightterror = 0;

void log(const string& text) {
    //cerr << text << endl;
}

vector<int> observe(Maze& maze, Mouse& mouse){

    vector<int> accessible_cells = {0, 0, 0}; //first element represent front, then right then left. 0 represents no wall (numeric_limits<int>::max()) --> represents wall present

    if(wallFront()){
            log("WallFront");
            accessible_cells[0]=1000;
            maze.getCell(mouse.position.first,mouse.position.second).setWall(mouse.direction,true);
            setWall(mouse.position.first, mouse.position.second, mouse.direction);
            cerr << mouse.position.first << endl;
            cerr << mouse.position.second << endl;
            //Wall is a interseaction between two cells(Update both cells)
            mouse.moveForward();
            mouse.rotateRight();
            mouse.rotateRight();
            cerr << mouse.position.first << endl;
            cerr << mouse.position.second << endl;
            maze.getCell(mouse.position.first,mouse.position.second).setWall(mouse.direction,true);
            log("move");
            setWall(mouse.position.first, mouse.position.second, mouse.direction);
            mouse.moveForward();
            mouse.rotateRight();
            mouse.rotateRight();
        }
    if(wallRight()){
        log("WallRight");
        accessible_cells[1]=1000;
        mouse.rotateRight();
        maze.getCell(mouse.position.first,mouse.position.second).setWall(mouse.direction,true);
        setWall(mouse.position.first, mouse.position.second, mouse.direction);

        //if move forwarf not an out of bound do this:
        mouse.moveForward();
        if(!(maze.getCell(mouse.position.first, mouse.position.second).floodfillValue == -1)){
            //Wall is a interseaction between two cells(Update both cells)
        mouse.rotateRight();
        mouse.rotateRight();
        maze.getCell(mouse.position.first,mouse.position.second).setWall(mouse.direction,true);
        setWall(mouse.position.first, mouse.position.second, mouse.direction);
        mouse.moveForward();
        mouse.rotateRight();
        mouse.rotateRight();
        }
        else{
        mouse.rotateRight();
        mouse.rotateRight();
        mouse.moveForward();
        mouse.rotateRight();
        mouse.rotateRight();
        }

        //reset the mouse back to orginal direction
        mouse.rotateLeft();
        
    }
    if(wallLeft()){
        log("WallLeft");
        accessible_cells[2]=1000;
        mouse.rotateLeft();
        maze.getCell(mouse.position.first,mouse.position.second).setWall(mouse.direction,true);
        setWall(mouse.position.first, mouse.position.second, mouse.direction);
        
        mouse.moveForward();
        //if move forwarf not an out of bound do this:
        if(!(maze.getCell(mouse.position.first, mouse.position.second).floodfillValue == -1)){
        //Wall is a interseaction between two cells(Update both cells)
        mouse.rotateRight();
        mouse.rotateRight();
        maze.getCell(mouse.position.first,mouse.position.second).setWall(mouse.direction,true);
        setWall(mouse.position.first, mouse.position.second, mouse.direction);
        mouse.moveForward();
        mouse.rotateRight();
        mouse.rotateRight();
        }
        else{
        mouse.rotateRight();
        mouse.rotateRight();
        mouse.moveForward();
        mouse.rotateRight();
        mouse.rotateRight();
        }
        //reset the mouse back to orginal direction
        mouse.rotateRight();
    }
    return accessible_cells;
}

void nextCell(Maze& maze, Mouse& mouse, vector<int>& accessible_cells){
    vector<int> neighbor_dist = {1000, 1000, 1000}; //first element represent front, then right then left
    log("nectCellRunning");
    mouse.moveForward();
    neighbor_dist[0]=maze.getFloodfill(mouse.position.first,mouse.position.second);
    cerr << "F" <<neighbor_dist[0] <<endl;
    mouse.rotateRight();
    mouse.rotateRight();
    mouse.moveForward();
    mouse.rotateRight();
    mouse.moveForward();
    neighbor_dist[2]=maze.getFloodfill(mouse.position.first,mouse.position.second);
    cerr << "L" <<neighbor_dist[1] <<endl;
    mouse.rotateRight();
    mouse.rotateRight();
    mouse.moveForward();
    mouse.moveForward();
    neighbor_dist[1]=maze.getFloodfill(mouse.position.first,mouse.position.second);
    cerr << "R" <<neighbor_dist[2] <<endl;
    mouse.rotateRight();
    mouse.rotateRight();
    mouse.moveForward();
    mouse.rotateRight();

    log("neighbor_dist");
    log(to_string(neighbor_dist[0]));
    log(to_string(neighbor_dist[1]));
    log(to_string(neighbor_dist[2]));

    vector<int> next_acc_cell = {neighbor_dist[0]+ accessible_cells[0] ,neighbor_dist[1]+accessible_cells[1] ,neighbor_dist[2]+accessible_cells[2]};
    log("next");
    log(to_string(next_acc_cell[0]));
    log(to_string(next_acc_cell[1]));
    log(to_string(next_acc_cell[2]));


    // Initialize variables to find the smallest value and its index
    int minValue = 2000; // Start with the maximum possible int value
    int minIndex = -1; // Initialize index to an invalid value

    // Iterate through the vector to find the minimum value and its index
    for (int i = 0; i < 3; ++i) {
        if (next_acc_cell[i] < minValue) {
            minValue = next_acc_cell[i];
            log("min");
            log(to_string(minValue));
            minIndex = i; // Update the index of the smallest value
        }
    }

    if(minValue>500){
        log("TurnAround");
            turnLeft();
            mouse.rotateLeft();

            turnLeft();
            mouse.rotateLeft();

            moveForward();
            mouse.moveForward();
    }
    else{
    // Use switch case to handle actions based on minVarName
    switch (minIndex) {  // Get the first character of minVarName
        case 0:
            log("Front");
            moveForward();
            mouse.moveForward();
            break;
        case 2:
            log("Left");
            turnLeft();
            mouse.rotateLeft();
            moveForward();
            mouse.moveForward();
            break;
        case 1:
            log("Right");
            turnRight();
            mouse.rotateRight();
            moveForward();
            mouse.moveForward();
            break;
        default:
            std::cout << "Error calculating the next cell" << std::endl;
            break;
         }
    }
}

void showFloodFillValues(Maze& maze){
    for (int i = maze.mazeWidth-1; i > -1; i--) {
        for (int j = 0; j < maze.mazeWidth; ++j) {
            setText(i,j,to_string(maze.getFloodfill(i,j)));
        }
        cout << endl;
    }
}


void setup(){
    delay(5000);
    Serial.begin(115200);
    sharpIR();
    motorDiver();
    motorInterrupt();
    attachInterrupt(digitalPinToInterrupt(PB1), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PA3), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB0), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PA12), countRightOut1, RISING);  
    pinMode(PA9, INPUT);
    pinMode(PA10, INPUT);
    pinMode(PA0, OUTPUT);
    
    vector<pair<int,int>> goal={{5,7}}; //Define the Goal cell
    Maze myMaze(16,goal); //Create the Maze obj
    Mouse myMouse('n',{0,0}); //Create the Mouse obj
    int search_turns = 3; //Define the number if search turns

    // int L_wallDistance=0;
    // int R_wallDistance=0;

    // if(wallRight()){
    //     for(int i=0; i<50; i++){
    //         R_wallDistance = R_wallDistance + analogRead(PA4);
    // }
    //     distance_wall = R_wallDistance/50;
    // }
    // else if(wallLeft()){
    //     for(int i=0; i<50; i++){
    //         L_wallDistance = L_wallDistance + analogRead(PA7);
    // }
    //         distance_wall = L_wallDistance/50;
    // }


    //floodfillAlgorithm(myMaze);

    //Start of the search runs
    for(int i=0; i<search_turns; i++){           
    
    fastrun =false;

    while(myMouse.position!= make_pair(5,7)){ //replace with GOAL  
        Serial.println("while");
        vector<int> accessible_cells = observe(myMaze,myMouse);
        floodfillAlgorithm(myMaze);
        //showFloodFillValues(myMaze);
        nextCell(myMaze,myMouse,accessible_cells);
    }
    delay(8000); //Delay before next Search Run
    ackReset(); //reset the mouse to initial position in the simulation/practical
    // Reset the mouse object
    myMouse.position.first = 0;
    myMouse.position.second = 0;
    myMouse.direction = 'n';
    digitalWrite(PA0, HIGH);
    delay(1000);
    digitalWrite(PA0,LOW);

    // while(check == precheck){
    //       check = digitalRead(PA9);
    //       delay(1000);
    //       if(digitalRead(PA10)){
    //         fastrun = true;
    //       }

    // }
    // if(check!=precheck){
    //     precheck=check;
    // }

    // if(fastrun){
    //     break;
    // }

    }   

    //FastRun
    while(myMouse.position!= make_pair(5,7)){ //replace with GOAL  
        vector<int> accessible_cells = observe(myMaze,myMouse);
        floodfillAlgorithm(myMaze); //Remove the floodfill calculation in the Fast Run
        //showFloodFillValues(myMaze);
        nextCell(myMaze,myMouse,accessible_cells);
    }
    digitalWrite(PA0, HIGH);
    delay(1000);
    digitalWrite(PA0,LOW);
    delay(1000);
    digitalWrite(PA0,HIGH);
    delay(1000);
    digitalWrite(PA0,LOW);
    delay(1000);
    digitalWrite(PA0,HIGH);
    delay(1000);
    digitalWrite(PA0,LOW);
}

void wallFollower2(){
    //delay(50);
    int L_sharpValue = 0;
    int R_sharpValue = 0;

    for(int i=0; i<50; i++){
    L_sharpValue = L_sharpValue + analogRead(PA7);
    R_sharpValue = R_sharpValue + analogRead(PA4);
    }
    L_sharpValue = L_sharpValue/50;
    R_sharpValue = R_sharpValue/50;
    int sharpError = L_sharpValue - R_sharpValue;
    // Serial.print("l   : ");
    // Serial.print(L_sharpValue);
    // Serial.print("   r : ");
    // Serial.println(R_sharpValue);
    bool left = wallLeft_frontsharp();
    bool right = wallRight_frontsharp();



    if (left && right){
        //delay(50);
        //if(wallLeft() && wallRight()){

        //}
        // state=0;
        // if (state != preState)
        // {
        //     jump = 2;
        //     rightLastError = 0;
        // }
        // if (jump>0)
        // {
        //     encoderPid();
        //     //forwardBase();
        //     jump = jump-1;
        // }
        // else{
        float kp = 0.04;
        leftPwm = leftBase + kp*sharpError;
        rightPwm = rightBase - kp*sharpError;
        // Serial.print("both");
        // Serial.println(sharpError);
        if (leftPwm>100){
            leftPwm =100;
        }
        else if (leftPwm <-100){
            leftPwm =-100;
        }

        if (rightPwm>100){
            rightPwm =100;
        }
        else if (rightPwm<- 100){
            rightPwm =-100;
        }
        forward();
        //}
    }

    else if (left){
        encoderPid();
        forward();
        // float kp_left = 0.009;
        // float lefterror = L_sharpValue -350 ;
        // // Serial.print("Left: ");
        // // Serial.println(lefterror);
       
        // leftPwm = leftBase + kp_left*lefterror;
        // rightPwm = rightBase - kp_left*lefterror;

        // if (leftPwm>100){
        //     leftPwm =100;
        // }
        // else if (leftPwm <-100){
        //     leftPwm =-100;
        // }

        // if (rightPwm>100){
        //     rightPwm =100;
        // }
        // else if (rightPwm<- 100){
        //     rightPwm =-100;
        // }
        // forward();
    }

    else if (right){
        encoderPid();
        forward();
        // float kp_right = 0.009;
        // float righterror = 350 - R_sharpValue;
        // // Serial.print("Right: ");
        // // Serial.println(righterror);
        
        // leftPwm = leftBase + kp_right*righterror;
        // rightPwm = rightBase - kp_right*righterror;

        // if (leftPwm>100){
        //     leftPwm =100;
        // }
        // else if (leftPwm <-100){
        //     leftPwm =-100;
        // }

        // if (rightPwm>100){
        //     rightPwm =100;
        // }
        // else if (rightPwm<- 100){
        //     rightPwm =-100;
        // }
        // forward();
        }
    else{
        encoderPid();
        forward();
    }
}

// void wallFollower2(){
//     //delay(50);
//     int L_sharpValue = 0;
//     int R_sharpValue = 0;

//     for(int i=0; i<50; i++){
//     L_sharpValue = L_sharpValue + analogRead(PA7);
//     R_sharpValue = R_sharpValue + analogRead(PA4);
//     }
//     L_sharpValue = L_sharpValue/50;
//     R_sharpValue = R_sharpValue/50;
//     int sharpError = L_sharpValue - R_sharpValue;
//     // Serial.print("l   : ");
//     // Serial.print(L_sharpValue);
//     // Serial.print("   r : ");
//     // Serial.println(R_sharpValue);
//     bool left = wallLeft_frontsharp();
//     bool right = wallRight_frontsharp();



//     if (left && right){
//         float kp = 0.04;
//         leftPwm = leftBase + kp*sharpError;
//         rightPwm = rightBase - kp*sharpError;
//         Serial.print("both");
//         Serial.println(sharpError);
//         if (leftPwm>100){
//             leftPwm =100;
//         }
//         else if (leftPwm <-100){
//             leftPwm =-100;
//         }

//         if (rightPwm>100){
//             rightPwm =100;
//         }
//         else if (rightPwm<- 100){
//             rightPwm =-100;
//         }
//         forward();
//         //}
//     }
//     else if (left || right){
//         if(left){
//             float kp_left = 0.07;
//             float kd_left = 0;
//             float lefterror = L_sharpValue -350 ;
//             float pid_error = kd_left*(previous_lefterror - lefterror) + kp_left*lefterror;
//             previous_lefterror=lefterror;
//             Serial.print("Left: ");
//             Serial.println(lefterror);
//             leftPwm = leftBase + kp_left*pid_error;
//             rightPwm = rightBase - kp_left*pid_error;
//         }else{
//             float kp_right = 0.07;
//             float kd_right = 0;
//             float righterror = 350 - R_sharpValue ;
//             float pid_error = kd_right*(previous_rightterror - righterror) + kp_right*righterror;
//             previous_rightterror=righterror;
//             leftPwm = rightBase + kp_right*righterror;
//             rightPwm = rightBase - kp_right*righterror;

//         }

//         encoderError = leftEncoder - rightEncoder;
//         if (encoderError > 50 )
//         {
//             encoderError = 10;
//         }
//         else if (encoderError < -50)
//         {
//             encoderError = -10;
//         }
//         encoderCorrection = float(encoderError * encoderP) + float(encoderLastError * encoderD);
//         encoderLastError = encoderError;
//         leftPwm = leftPwm - encoderCorrection;
//         rightPwm = rightPwm + encoderCorrection;
        

//         if (leftPwm>100){
//             leftPwm =100;
//         }
//         else if (leftPwm <-100){
//             leftPwm =-100;
//         }

//         if (rightPwm>100){
//             rightPwm =100;
//         }
//         else if (rightPwm<- 100){
//             rightPwm =-100;
//         }
//         forward();
        
//     }
//     else{
//         encoderPid();
//         forward();
//     }
// }

//Following a single wall
void wallFollower_singleWall(){
    delay(10);
    int L_sharpValue = 0;
    int R_sharpValue = 0; 
    L_sharpValue = L_sharpValue + analogRead(PA7);
    R_sharpValue = R_sharpValue + analogRead(PA4);
    int sharpError = L_sharpValue - R_sharpValue;

    // Serial.print("l   : ");
    // Serial.print(L_sharpValue);
    // Serial.print("   r : ");
    // Serial.println(R_sharpValue);
    bool left = wallLeft();
    bool right = wallRight();

    if (left){
        float kp_left = 0.07;
        float kd_left = 0;
        float lefterror = L_sharpValue -373 ;
        float pid_error = kd_left*(previous_lefterror - lefterror) + kp_left*lefterror;
        Serial.print("Left: ");
        Serial.println(lefterror);
        leftPwm = leftBase + kp_left*pid_error;
        rightPwm = rightBase - kp_left*pid_error;

        if (leftPwm>100){
            leftPwm =100;
        }
        else if (leftPwm <-100){
            leftPwm =-100;
        }

        if (rightPwm>100){
            rightPwm =100;
        }
        else if (rightPwm<- 100){
            rightPwm =-100;
        }
        forward();
        previous_lefterror=lefterror;
    }

    else if (right){
        float kp_right = 0.07;
        float kd_right = 0;
        float righterror = L_sharpValue -373 ;
        float pid_error = kd_right*(previous_rightterror - righterror) + kp_right*righterror;
        leftPwm = rightBase + kp_right*righterror;
        rightPwm = rightBase - kp_right*righterror;

        if (leftPwm>100){
            leftPwm =100;
        }
        else if (leftPwm <-100){
            leftPwm =-100;
        }

        if (rightPwm>100){
            rightPwm =100;
        }
        else if (rightPwm<- 100){
            rightPwm =-100;
        }
        forward();
    }
    else{
        encoderPid();
        forward();
    }
    // cellForward();
    // brake();
    // delay(3000);
}

void cellAlign(){
    //delay(50);
    int L_sharpValue = 0;
    int R_sharpValue = 0;

    for(int i=0; i<50; i++){
    L_sharpValue = L_sharpValue + analogRead(PA7);
    R_sharpValue = R_sharpValue + analogRead(PA4);
    }
    L_sharpValue = L_sharpValue/50;
    R_sharpValue = R_sharpValue/50;
    int sharpError = L_sharpValue - R_sharpValue;
    // Serial.print("l   : ");
    // Serial.print(L_sharpValue);
    // Serial.print("   r : ");
    // Serial.println(R_sharpValue);
    bool left = wallLeft();
    bool right = wallRight();



    if (left && right){
        float kp = 0.004;
        leftPwm = kp*sharpError;
        rightPwm = kp*sharpError;
        Serial.print("both");
        Serial.println(sharpError);
        if (leftPwm>100){
            leftPwm =100;
        }
        else if (leftPwm <-100){
            leftPwm =-100;
        }

        if (rightPwm>100){
            rightPwm =100;
        }
        else if (rightPwm<- 100){
            rightPwm =-100;
        }
        forward2();
    }

    else if (left){
        float kp_left = 0.008;
        float lefterror = L_sharpValue -373 ;
        Serial.print("Left: ");
        Serial.println(lefterror);
        if(lefterror<10){
            lefterror = 0;
        }
        leftPwm = kp_left*lefterror;
        rightPwm = - kp_left*lefterror;

        if (leftPwm>100){
            leftPwm =100;
        }
        else if (leftPwm <-100){
            leftPwm =-100;
        }

        if (rightPwm>100){
            rightPwm =100;
        }
        else if (rightPwm<- 100){
            rightPwm =-100;
        }
        // forward();
    }

    else if (right){
        float kp_right = 0.008;
        float righterror = 373 - R_sharpValue;
        Serial.print("Right: ");
        Serial.println(righterror);
        if(righterror<10){
            righterror = 0;
        }
        leftPwm = kp_right*righterror;
        rightPwm = -kp_right*righterror;

        if (leftPwm>100){
            leftPwm =100;
        }
        else if (leftPwm <-100){
            leftPwm =-100;
        }

        if (rightPwm>100){
            rightPwm =100;
        }
        else if (rightPwm<- 100){
            rightPwm =-100;
        }
        // forward();
    }
    // cellForward();
    // brake();
    // delay(3000);
    preState =state;
}


///Car ekedi gahuwe
void cellAdjust(){
    int L_sharpValue = 0;
    int R_sharpValue = 0;
    for(int i=0; i<10;i++){
        L_sharpValue = L_sharpValue + analogRead(PA7);
        R_sharpValue = R_sharpValue + analogRead(PA4);
    }
    int prev_L_sharpValue = 1000;
    int prev_R_sharpValue = 1000;

    if(L_sharpValue>200 || R_sharpValue>200){
        Serial.println("walls are there");
        if(L_sharpValue>R_sharpValue){
            Serial.println("L>R");
            while(1){
                prev_L_sharpValue = L_sharpValue; 
                cellTikka_Right();
                
                L_sharpValue = 0;
                R_sharpValue = 0;
                for(int i=0; i<10;i++){
                    L_sharpValue = L_sharpValue + analogRead(PA7);
                    R_sharpValue = R_sharpValue + analogRead(PA4);
                }
                L_sharpValue = L_sharpValue/10;
                int error = prev_L_sharpValue - L_sharpValue;
                Serial.print("error: ");
                Serial.println(error);
                if(error>0){
                    break;
                }
            }
        }
        else if(R_sharpValue>L_sharpValue){
                Serial.println("L<R");
            while(1){
                prev_R_sharpValue = R_sharpValue; 
                cellTikka_Left();
                R_sharpValue = analogRead(PA4);

                L_sharpValue = 0;
                R_sharpValue = 0;
                for(int i=0; i<10;i++){
                    L_sharpValue = L_sharpValue + analogRead(PA7);
                    R_sharpValue = R_sharpValue + analogRead(PA4);
                }
                R_sharpValue = R_sharpValue/10;
                int error = prev_R_sharpValue - R_sharpValue;
                Serial.print("error: ");
                Serial.println(error);
                if(error>0){
                    break;
                }
            }
        }
    }
}



void loop(){
    //cellForward();
    //wallLeft();
    //wallRight();
    // wallFront();
    //delay(500);
    // display.clearDisplay();
    // delay(100);
    // int c = wallFront();
    // display_line(String(c),0,20,2);
    // delay(1000);
    // display.clearDisplay();
//     // cellForward();
//     // brake();
//     // cellAlign();
//     // delay(3000);
//   check = digitalRead(PA9);
//   delay(1000);
//   if(check != precheck){
//     //rightAboutTurn();
//     //leftAboutTurn(); has to callibrate
//     //rightHalfTurn(); has to callibrate
//     //leftHalfTurn(); //has to callibrate
//     rightHalfTurn();
//     precheck = check;
//   }
}


// void wall_plus_encorder(){
//     delay(10);
//     int L_sharpValue = 0;
//     int R_sharpValue = 0; 
//     L_sharpValue = L_sharpValue + analogRead(PA7);
//     R_sharpValue = R_sharpValue + analogRead(PA4);
//     int sharpError = L_sharpValue - R_sharpValue;

//     bool left = wallLeft();
//     bool right = wallRight();

//     if (left || right){
//         if(left){
//             float kp_left = 0.07;
//             float kd_left = 0;
//             float lefterror = 350 -373 ;
//             float pid_error = kd_left*(previous_lefterror - lefterror) + kp_left*lefterror;
//             previous_lefterror=lefterror;
//             Serial.print("Left: ");
//             Serial.println(lefterror);
//             leftPwm = leftBase + kp_left*pid_error;
//             rightPwm = rightBase - kp_left*pid_error;
//         }else{
//             float kp_right = 0.07;
//             float kd_right = 0;
//             float righterror = 350 -373 ;
//             float pid_error = kd_right*(previous_rightterror - righterror) + kp_right*righterror;
//             leftPwm = rightBase + kp_right*righterror;
//             rightPwm = rightBase - kp_right*righterror;

//         }

//         encoderError = leftEncoder - rightEncoder;
//         if (encoderError > 50 )
//         {
//             encoderError = 10;
//         }
//         else if (encoderError < -50)
//         {
//             encoderError = -10;
//         }
//         encoderCorrection = float(encoderError * encoderP) + float(encoderLastError * encoderD);
//         encoderLastError = encoderError;
//         leftPwm = leftPwm - encoderCorrection;
//         rightPwm = rightPwm + encoderCorrection;
        

//         if (leftPwm>100){
//             leftPwm =100;
//         }
//         else if (leftPwm <-100){
//             leftPwm =-100;
//         }

//         if (rightPwm>100){
//             rightPwm =100;
//         }
//         else if (rightPwm<- 100){
//             rightPwm =-100;
//         }
//         forward();
        
//     }
//     else{
//         encoderPid();
//         forward();
//     }   
// }


    




    
