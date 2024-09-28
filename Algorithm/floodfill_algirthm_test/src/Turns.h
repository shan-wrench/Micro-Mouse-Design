#pragma once
void countLeftOut1()
{
    leftEncoder = leftEncoder + 1;   
}

void countRightOut1()
{
    rightEncoder = rightEncoder + 1;
}

void turnBack()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        Right();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 725;
    encoderLeftCount= encoderLeftCount + 725;
    while(rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        Right();
    }
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        Right();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void rightAboutTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    rightBase = 70;
    leftBase = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        Right();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 240;
    encoderLeftCount= encoderLeftCount + 240;
    while(rightEncoder <= encoderRightCount)
    {
        Right();
    }
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        Right();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void leftAboutTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    rightBase = 70;
    leftBase = 70;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        Left();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 255;
    encoderLeftCount= encoderLeftCount + 255;
    while(rightEncoder <= encoderRightCount)
    {
        Left();
    }
    
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        Left();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void rightHalfTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 61;
    encoderLeftCount= encoderLeftCount + 61;
    rightBase_turn90 = 70;
    leftBase_turn90 = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        Right();
    }
    rightBase_turn90=176;
    leftBase_turn90=180;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while(rightEncoder <= encoderRightCount)
    {
        Right();
    }
    encoderRightCount= encoderRightCount + 61;
    encoderLeftCount= encoderLeftCount + 61;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        Right();  
    }
    brake();
    leftBase_turn90 = 180;
    rightBase_turn90 = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void leftHalfTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 57;
    encoderLeftCount= encoderLeftCount + 57;
    rightBase_turn90 = 70;
    leftBase_turn90 = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        Left();
    }
    rightBase_turn90=176;
    leftBase_turn90=180;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while(rightEncoder <= encoderRightCount)
    {
        Left();
    }
    encoderRightCount= encoderRightCount + 57;
    encoderLeftCount= encoderLeftCount + 57;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        Left();  
    }
    brake();
    leftBase_turn90 = 180;
    rightBase_turn90 = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}




///Car
void cellTikka_Left()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    rightBase_turn90 = 70;
    leftBase_turn90 = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        Left();
    }
    rightBase_turn90=176;
    leftBase_turn90=180;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while(rightEncoder <= encoderRightCount)
    {
        Left();
    }
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        Left();  
    }
    brake();
    leftBase_turn90 = 180;
    rightBase_turn90 = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}


void cellTikka_Right()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    rightBase_turn90 = 70;
    leftBase_turn90 = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        Right();
    }
    rightBase_turn90=176;
    leftBase_turn90=180;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while(rightEncoder <= encoderRightCount)
    {
        Right();
    }
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase_turn90 = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase_turn90 = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        Right();  
    }
    brake();
    leftBase_turn90 = 180;
    rightBase_turn90 = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}


