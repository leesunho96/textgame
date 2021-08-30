#pragma once
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <time.h>

#define LeftPoint 23
#define LEFTMOVESIZE 4
#define VERTICALSIZE 19
#define HEIGHTPOINT 5
#define HEIGHTMOVESIZE 1
#define HORIZENTALSIZE 13
#define None 0
#define PLAYER 1
#define ENEMY 2
#define UNLOCK 3;
#define OPEN 4;

using namespace std;


void gotoxy(int x, int y);
//{
//	COORD pos = { x,y };
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}