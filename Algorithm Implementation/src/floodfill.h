#pragma once
#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <vector>
#include <utility>
#include <queue>
#include <map>

#include "mouse.h"
#include "maze.h" //Make sure to not have circuilar dependencies

// Function declaration for the floodfill algorithm
void floodfillAlgorithm(Maze& maze);

#endif // FLOODFILL_H
