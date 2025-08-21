#ifndef __ATTENDANCE_H__
#define __ATTENDANCE_H__
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::cout;
using std::string;
using std::map;
using std::endl;
using std::ifstream;

typedef enum {
    GOLD = 1,
    SILVER = 2,
    NORMAL = 3
}grade_e;

const char* MON = "monday";
const char* TUE = "tuesday";
const char* WED = "wednesday";
const char* THU = "thursday";
const char* FRI = "friday";
const char* SAT = "saturday";
const char* SUN = "sunday";
const int MAX_ATTENDANCE_DATA_LEN = 500;
const int WEDNESSDAY_INDEX = 2;
const int SATURDAY_INDEX = 5;
const int SUNDAY_INDEX = 6;

map<string, int> playerIdMap;
int playerIdCnt = 0;
string playerNameArr[100];
int playerPoint[100];
int playerRemoved[100];
int playerGrade[100];
int attendCntDayById[100][100];
int attendCntWednesday[100];
int attendCntWeekend[100];
string arrDayOfWeek[7] = { MON, TUE, WED, THU, FRI, SAT, SUN };

void setPlayerId(string playerName);
void updateRemovePlayer();
void updataBonusPoint();
void updatePlayerGrade();
void handleInputData();
void increasePoint(int targetId, string dayOfWeek);
void setAttendCntDaybyId(int targetId, string dayOfWeek);
bool isRemovePlayer(int i);
void logPrintResult();
void logPrintRemovePlayer();

#endif // __ATTENDANCE_H__
