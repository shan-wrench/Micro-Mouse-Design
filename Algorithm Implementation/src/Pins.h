#pragma once
#include <Arduino.h>


// #define PWMA PB7    //motor driver pins
// #define AIN2 PA12
// #define AIN1 PA7
// #define STBY PA11
// #define BIN1 PB0
// #define BIN2 PB1
// #define PWMB PB6

#define AIN1 PA8// left
#define AIN2 PA11
#define PWMA PA2

#define BIN1 PB4 //right
#define BIN2 PB5
#define PWMB PA1

#define leftOut1 PB1   //interrupt pins of motors 
#define leftOut2 PA3      
#define rightOut1 PB0
#define rightOut2 PA12

#define sharpl PA7 // left
#define sharpr PA4 // right
#define sharpc PA3 // center


void motorDiver()
{
    pinMode(PWMA, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);
}

void motorInterrupt()
{
    pinMode(leftOut1, INPUT);
    pinMode(leftOut2, INPUT);
    pinMode(rightOut1, INPUT);
    pinMode(rightOut2, INPUT);
}

void sharpIR()
{
    pinMode(sharpl, INPUT);
    pinMode(sharpr, INPUT);
    pinMode(sharpc, INPUT);
}



