#pragma once
// void stbyHigh()
// {
//     digitalWrite(STBY, HIGH);
// }

// void stbyLow()
// {
//     digitalWrite(STBY, LOW);
// }

void leftForward()
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
}

void leftReverse()
{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
}

void leftBrake()
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, HIGH);
}

void leftForwardBase()
{
    leftForward();
    analogWrite(PWMA, leftBase);
}

void leftReverseBase()
{
    leftReverse();
    analogWrite(PWMA, leftBase);
}

void rightForward()
{
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
}

void rightReverse()
{
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
}

void rightBrake()
{
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, HIGH);
}

void rightForwardBase()
{
    rightForward();
    analogWrite(PWMB, rightBase);
}

void rightReverseBase()
{
    rightReverse();
    analogWrite(PWMB, rightBase);
}

void writePwm()
{
    analogWrite(PWMA, leftPwm);
    analogWrite(PWMB, rightPwm);
}

void writeBasePwm()
{
    analogWrite(PWMA, leftBase_turn90);
    analogWrite(PWMB, rightBase_turn90);
}

void forward()
{
    leftForward();
    rightForward();
    writePwm();
}

void forward2()
{
    if(leftPwm < 0){
        leftReverse();
        rightForward();
        leftPwm = -leftPwm;
        rightPwm = -rightPwm;
    }
    else{
        rightReverse();
        leftForward();
    }
    
    writePwm();
}

void reverse()
{
    leftReverse();
    rightReverse();
    writePwm();
}

void brake()
{
    leftBrake();
    rightBrake();
    delay(75);
}

void brakeNo()
{
    leftBrake();
    rightBrake();
    //delay(100);
}

void forwardBase()
{
    leftForward();
    rightForward();
    writeBasePwm();
}

void reverseBase()
{
    leftReverse();
    rightReverse();
    writeBasePwm();
}

void Right()
{
    leftForward();
    rightReverse();
    writeBasePwm();
}

void Left()
{
    leftReverse();
    rightForward();
    writeBasePwm();
}
