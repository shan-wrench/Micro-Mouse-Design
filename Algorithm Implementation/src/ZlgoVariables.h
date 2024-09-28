#pragma once
#include <QueueArray.h>

uint8_t x=0;
uint8_t y=0;

uint8_t xprev=0;
uint8_t yprev=0;
uint8_t orient=0;
uint8_t state=0;
bool shortPath= false;
bool middleSquare= true;
uint8_t x_0;
uint8_t y_0;
uint8_t x_1;
uint8_t y_1;
uint8_t x_2;
uint8_t y_2;
uint8_t x_3;
uint8_t y_3;
uint8_t mazeSize = 16;
char dir;
char turning;
// QueueArray <uint8_t> queue;
// QueueArray <uint8_t> pathQueue;
bool  L = true;
bool  R= true;
bool  F= false; 
uint8_t xdes;
uint8_t ydes;
unsigned long timer;
int cellCount =0;
bool runningNext;

uint8_t cells[14][14] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         // (and so on)
                        };

uint8_t flood2[14][14] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         // (and so on)
                        };

uint8_t flood[14][14] = {{12,11,10,9,8,7,6,6,7,8,9,10,11,12},
                         // (and so on)
                        };

uint8_t sliit[14][14] = {{11,11,11,11,14,10,12,5,6,5,4,10,10,12},
                         // (and so on)
                        };

char bluetoothWalls;
uint8_t xrun=0;
uint8_t yrun=0;
