#pragma once
void leftPid()
{
    leftError = 30 - tof[0];
    leftDiff = leftError - leftLastError;

    if (leftDiff > 50 )
    {
        leftError = 10;
        leftDiff = 5;
    }

    else if (leftDiff < -50)
    {
        leftError = -20;
        leftDiff = -5;
    }
    

    float leftP_dynamic = leftP;
    if (abs(leftError) > 50) {       // Large error, increase P
        leftP_dynamic = leftP * 1.5; 
    } else if (abs(leftError) < 10) { // Small error, decrease P
        leftP_dynamic = leftP * 0.5;
    }

    // Dynamically adjust the derivative gain (D)
    float leftD_dynamic = leftD;
    if (abs(leftDiff) > 50) {        // Large derivative, increase D for damping
        leftD_dynamic = leftD * 1.5;
    } else if (abs(leftDiff) < 10) { // Small derivative, decrease D to avoid over-damping
        leftD_dynamic = leftD * 0.5;
    }

    // Compute correction with adaptive P and D
    correction = (leftError * leftP_dynamic) + (leftDiff * leftD_dynamic);
    leftLastError = leftError;
    
    // if (leftDiff > 50 )
    // {
    //     leftError = 10;
    //     leftDiff = 5;
    // }

    // else if (leftDiff < -50)
    // {
    //     leftError = -20;
    //     leftDiff = -5;
    // }
    
    
    // correction = (leftError * leftP) + (leftDiff * leftD);
    // leftLastError = leftError;
    
    // if (correction > 50 )
    // {
    //     correction = 15;
    // }

    // else if (correction < -50)
    // {
    //     correction = -50;
    // }

    // Limit correction to reduce overshooting
    if (correction > 15) {
        correction = 15;
    } else if (correction < -15) {
        correction = -15;
    }
    
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 30 - tof[4];
    rightDiff = rightError - rightLastError;

    if (correction > 50 )
    {
        correction = 15;
    }

    else if (correction < -50)
    {
        correction = -15;
    }
      
    // Dynamically adjust the proportional gain (P)
    float rightP_dynamic = rightP;
    if (abs(rightError) > 50) {          // If the error is large, increase P
        rightP_dynamic = rightP * 2;
    } else if (abs(rightError) < 10) {   // If the error is small, reduce P
        rightP_dynamic = rightP * 0.5;
    }

    // Dynamically adjust the derivative gain (D)
    float rightD_dynamic = rightD;
    if (abs(rightDiff) > 50) {           // If the change in error is large, increase D
        rightD_dynamic = rightD * 1.5;
    } else if (abs(rightDiff) < 10) {    // If the change in error is small, reduce D
        rightD_dynamic = rightD * 0.5;
    }

    // Compute the correction with adaptive P and D
    correction = (rightError * rightP_dynamic) + (rightDiff * rightD_dynamic);
    rightLastError = rightError;  // Update the last error

    // Limit correction to avoid overshoot or instability
    if (correction > 15) correction = 15;
    if (correction < -15) correction = -15;

    // correction  = (rightError * rightP) + (rightDiff * rightD);
    // rightLastError = rightError;
    
    // if (correction > 50 )
    // {
    //     correction = 15;
    // }

    // else if (correction < -50)
    // {
    //     correction = -15;
    // }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}


void wallPid()
{
    wallError = tof[0] - (tof[4]);
    rightLastError = 25 - tof[4];
    leftLastError = 25 - tof[0];
    wallDiff = wallError - wallLastError;
    
    if (wallDiff > 50 )
    {
        wallError = 10;
        wallDiff = 5;
    }

    else if (wallDiff < -50)
    {
        wallError = -10;
        wallDiff = -5;
    }
    
    correction = (wallError * wallP) + (wallDiff * wallD);
    wallLastError = wallError;
    
    if (correction > 50 )
    {
        correction = 10;
    }

    else if (correction < -50)
    {
        correction = -10;
    }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void encoderPid()
{
    encoderError = leftEncoder - rightEncoder;
    if (encoderError > 50 )
    {
        encoderError = 10;
    }
    else if (encoderError < -50)
    {
        encoderError = -10;
    }
    encoderCorrection = float(encoderError * encoderP) + float(encoderLastError * encoderD);
    encoderLastError = encoderError;
    leftPwm = leftBase - encoderCorrection;
    rightPwm = rightBase + encoderCorrection;
    forward();
}


void encoderPid_turnready()
{
    encoderError = leftEncoder - rightEncoder;
    if (encoderError > 50 )
    {
        encoderError = 10;
    }
    else if (encoderError < -50)
    {
        encoderError = -10;
    }
    encoderCorrection = float(encoderError * encoderP) + float(encoderLastError * encoderD);
    encoderLastError = encoderError;
    leftPwm = leftBase -30- encoderCorrection;
    rightPwm = rightBase - 30 + encoderCorrection;
    forward();
}


void wallFollow()
{
    tofPid();
    if (tof[0] <= 150 && tof[4] <= 150)
    {
        state = 0;
        if (state != preState)
        {
          jump = 5;
          wallLastError = 0;
        }
        if (jump>0)
        {
          //forwardBase();
          encoderPid();
          jump = jump-1;
        }
        else
        {
          wallPid();
          forward();
        }
    }

    else if (tof[0] > 150 && tof[4] <= 150)
    {
        state = 1;
        if (state != preState)
        {
          jump = 5;
          rightLastError = 0;
        }
        if (jump>0)
        {
          encoderPid();
          //forwardBase();
          jump = jump-1;
        }
        else
        {
          rightPid();
          forward();
        }
    }

    else if (tof[0] <= 150 && tof[4] > 150)
    {
        state = 2;
        if (state != preState)
        {
          jump = 5;
          leftLastError = 0;
        }
        if (jump>0)
        {
          encoderPid();
          //forwardBase();
          jump = jump-1;
        }
        else
        {
          leftPid();
          forward();
        }
    }
    else if(tof[0] > 150 && tof[4] > 150)
    {
        state = 3;
        encoderPid();
        //forwardBase();
        wallLastError = 0;
    }
    preState = state;
}  
