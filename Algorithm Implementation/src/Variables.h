#pragma once
int r = -3;
int leftBase =79 - r;
int rightBase = 79 + r;
int leftPwm = 79 - r;
int rightPwm = 79 + r;

unsigned long leftEncoder = 0;
unsigned long rightEncoder = 0;
unsigned long encoderLeftCount = 0;
unsigned long encoderRightCount = 0;

int leftBase_turn90 = 0;
int rightBase_turn90 = 0;

int dif = 0;
int test = 0;

float tof[5];
int wallAvailable[3];
int cellWalls[3];

int leftWallAvailable = 0;
int rightWallAvailable = 0;
int frontWallAvailable = 0;

int rightWall  = 1;
int leftWall = 1;

float leftP = 0.6;
float leftD = 4;

float leftError = 0;
float leftLastError = 0;
float leftDiff = 0;

float rightP = 0.5;
float rightD = 8;

float rightError = 0;
float rightLastError = 0;
float rightDiff = 0;

float wallP = 0.5 ;
float wallD = 0; 

float wallError = 0;
float wallLastError = 0;
float wallDiff = 0;

float encoderP = 0.5 ;
float encoderD = 0; 

float encoderError = 0;
float encoderLastError = 0;
float encoderDiff = 0;

float encoderCorrection = 0;
float correction;

char nextMove = 'F';

int start = 0;

int customTime;


bool left,right,front;
int cell =0;

int jump = 0;
int preState = 0;
int selectMode = -1;

int distance_wall;