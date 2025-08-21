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

class AttendanceSystem {
public:
    AttendanceSystem();

    virtual void setPlayerId(const string& playerName);
    virtual void updateRemovePlayer();
    virtual void updataBonusPoint();
    virtual void handleInputData();
    virtual void increasePoint(int targetId, const string& dayOfWeek);
    virtual void setAttendCntDaybyId(int targetId, const string& dayOfWeek);
    virtual bool isRemovePlayer(int i) const;
    virtual void logPrintResult() const;
    virtual void logPrintRemovePlayer() const;
    virtual void processAttendSystem();
    virtual void updatePlayerGrade();
    const map<string, int>& getPlayerIdMap() const { return playerIdMap; }
    void setPlayerIdMap(const map<string, int>& m) { playerIdMap = m; }
    int getPlayerIdCnt() const { return playerIdCnt; }
    void setPlayerIdCnt(int cnt) { playerIdCnt = cnt; }
    const string& getPlayerName(int idx) const { return playerNameArr[idx]; }
    void setPlayerName(int idx, const string& name) { playerNameArr[idx] = name; }
    int getPlayerPoint(int idx) const { return playerPoint[idx]; }
    void setPlayerPoint(int idx, int point) { playerPoint[idx] = point; }
    int getPlayerRemoved(int idx) const { return playerRemoved[idx]; }
    void setPlayerRemoved(int idx, int val) { playerRemoved[idx] = val; }
    int getPlayerGrade(int idx) const { return playerGrade[idx]; }
    void setPlayerGrade(int idx, int grade) { playerGrade[idx] = grade; }
    int getAttendCntDayById(int id, int dayIdx) const { return attendCntDayById[id][dayIdx]; }
    void setAttendCntDayById(int id, int dayIdx, int val) { attendCntDayById[id][dayIdx] = val; }
    int getAttendCntWednesday(int idx) const { return attendCntWednesday[idx]; }
    void setAttendCntWednesday(int idx, int val) { attendCntWednesday[idx] = val; }
    int getAttendCntWeekend(int idx) const { return attendCntWeekend[idx]; }
    void setAttendCntWeekend(int idx, int val) { attendCntWeekend[idx] = val; }
    const string& getArrDayOfWeek(int idx) const { return arrDayOfWeek[idx]; }
    void setArrDayOfWeek(int idx, const string& val) { arrDayOfWeek[idx] = val; }

    const char* MON = "monday";
    const char* TUE = "tuesday";
    const char* WED = "wednesday";
    const char* THU = "thursday";
    const char* FRI = "friday";
    const char* SAT = "saturday";
    const char* SUN = "sunday";

    typedef enum {
        GOLD = 1,
        SILVER = 2,
        NORMAL = 3
    } grade_e;
private:
    map<string, int> playerIdMap;
    int playerIdCnt;
    string playerNameArr[100];
    int playerPoint[100];
    int playerRemoved[100];
    int playerGrade[100];
    int attendCntDayById[100][100];
    int attendCntWednesday[100];
    int attendCntWeekend[100];
    string arrDayOfWeek[7];

    const int MAX_ATTENDANCE_DATA_LEN = 500;
    const int WEDNESSDAY_INDEX = 2;
    const int SATURDAY_INDEX = 5;
    const int SUNDAY_INDEX = 6;
};

#endif // __ATTENDANCE_H__