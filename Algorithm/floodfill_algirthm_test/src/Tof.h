#pragma once
void tofPid()
{
    tof[0] = shar_l();
    tof[2] = sharp_c();
    tof[4] = shar_r();
}

// void tofStart()
// {
//     tof[1] = tof1.readRangeSingleMillimeters();
//     tof[2] = tof3.readRangeSingleMillimeters();
//     tof[3] = tof5.readRangeSingleMillimeters();
// }
void printTof()
{
    
    Serial2.print(tof[0]);
    Serial2.print(",  ");
    Serial2.print(tof[2]);
    Serial2.print(",  ");
    Serial2.print(tof[4]);
    Serial2.println();
}

// void checkWallsCell()
// {
//     if (x == 0 && y == 0)
//     {
//         time = 0;
//         while(time <10)
//         {
//             tofStart();
//             if (tof[2] <= 180)
//             {
//             frontWallAvailable = frontWallAvailable + 1;
//             }
//             else
//             {
//             frontWallAvailable = frontWallAvailable - 1;
//             }
//             if (tof[1] <= 150)
//             {
//             leftWallAvailable= leftWallAvailable + 1;
//             }
//             else
//             {
//             leftWallAvailable= leftWallAvailable - 1;
//             }
//             if (tof[3] <= 150)
//             {
//             rightWallAvailable= rightWallAvailable + 1;
//             }
//             else
//             {
//             rightWallAvailable= rightWallAvailable - 1;
//             }
//             time = time + 1;
//         }
//     }
//     if (frontWallAvailable >=0 )
//     {
//         cellWalls[1] =  0;
//         F = true;
//         //frontWallAvailable = 0;
//     }
//     else
//     {
//         cellWalls[1] =  1;
//         F = false;
//         //frontWallAvailable = 0;
//     } 
//     if (leftWallAvailable >= 0)
//     {
//         cellWalls[0] = 1;
//         L = true;
//         //leftWallAvailable = 0;
//     }
//     else
//     {
//         cellWalls[0] = 0;
//         L = false;
//         //leftWallAvailable = 0;
//     }
//     if (rightWallAvailable >= 0)
//     {
//         cellWalls[2] = 1;
//         R = true;
//         //rightWallAvailable = 0;
//     }
//     else
//     {
//         cellWalls[2] = 0;
//         R = false;
//         //rightWallAvailable = 0;
//     }
    
// }

// void printWallState()
// {
//     for (int i=0; i<3; i++)
//     {
//         Serial2.print(cellWalls[i]);
//         Serial2.print("   ");
//     }
//     Serial2.println("");
// }
