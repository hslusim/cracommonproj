#include "attendance.h"

AttendanceSystem::AttendanceSystem()
    : playerIdCnt(0),
    arrDayOfWeek{ MON, TUE, WED, THU, FRI, SAT, SUN }
{
    std::fill(playerNameArr, playerNameArr + 100, "");
    std::fill(playerPoint, playerPoint + 100, 0);
    std::fill(playerRemoved, playerRemoved + 100, 0);
    std::fill(playerGrade, playerGrade + 100, 0);
    std::fill(attendCntWednesday, attendCntWednesday + 100, 0);
    std::fill(attendCntWeekend, attendCntWeekend + 100, 0);
    for (int i = 0; i < 100; ++i)
        std::fill(attendCntDayById[i], attendCntDayById[i] + 100, 0);
}

void AttendanceSystem::setPlayerId(const string& playerName) {
    if (playerIdMap.count(playerName) == 0) {
        playerIdMap[playerName] = ++playerIdCnt;
        playerNameArr[playerIdCnt] = playerName;
    }
}

void AttendanceSystem::setAttendCntDaybyId(int targetId, const string& dayOfWeek) {
    if (targetId > playerIdCnt) {
        cout << "Invalid player ID" << endl;
        return;
    }
    for (int i = 0; i < 7; i++) {
        if (arrDayOfWeek[i] == dayOfWeek) {
            attendCntDayById[targetId][i] += 1;
            break;
        }
    }
}

void AttendanceSystem::increasePoint(int targetId, const string& dayOfWeek) {
    if (targetId > playerIdCnt) {
        cout << "Invalid player ID" << endl;
        return;
    }
    if (dayOfWeek == WED) {
        playerPoint[targetId] += 3;
        attendCntWednesday[targetId] += 1;
    }
    else if (dayOfWeek == SAT || dayOfWeek == SUN) {
        playerPoint[targetId] += 2;
        attendCntWeekend[targetId] += 1;
    }
    else {
        playerPoint[targetId] += 1;
    }
}

bool AttendanceSystem::isRemovePlayer(int i) const {
    return playerGrade[i] != GOLD && playerGrade[i] != SILVER &&
        attendCntWednesday[i] == 0 && attendCntWeekend[i] == 0;
}

void AttendanceSystem::updateRemovePlayer() {
    for (int i = 1; i <= playerIdCnt; i++) {
        if (isRemovePlayer(i)) {
            playerRemoved[i] = 1;
        }
    }
}

void AttendanceSystem::updataBonusPoint() {
    for (int i = 1; i <= playerIdCnt; i++) {
        if (attendCntDayById[i][WEDNESSDAY_INDEX] > 9) {
            playerPoint[i] += 10;
        }
        if (attendCntDayById[i][SATURDAY_INDEX] + attendCntDayById[i][SUNDAY_INDEX] > 9) {
            playerPoint[i] += 10;
        }
    }
}

void AttendanceSystem::updatePlayerGrade() {
    for (int i = 1; i <= playerIdCnt; i++) {
        if (playerPoint[i] >= 50) {
            playerGrade[i] = GOLD;
        }
        else if (playerPoint[i] >= 30) {
            playerGrade[i] = SILVER;
        }
        else {
            playerGrade[i] = NORMAL;
        }
    }
}

void AttendanceSystem::handleInputData() {
    ifstream fin{ "attendance_weekday_500.txt" };
    for (int i = 0; i < MAX_ATTENDANCE_DATA_LEN; i++) {
        string playerName, dayOfWeek;
        fin >> playerName >> dayOfWeek;
        setPlayerId(playerName);
        setAttendCntDaybyId(playerIdMap[playerName], dayOfWeek);
        increasePoint(playerIdMap[playerName], dayOfWeek);
    }
}

void AttendanceSystem::logPrintResult() const {
    for (int i = 1; i <= playerIdCnt; i++) {
        cout << "NAME : " << playerNameArr[i] << ", ";
        cout << "POINT : " << playerPoint[i] << ", ";
        cout << "GRADE : ";
        if (playerGrade[i] == GOLD) {
            cout << "GOLD" << "\n";
        }
        else if (playerGrade[i] == SILVER) {
            cout << "SILVER" << "\n";
        }
        else {
            cout << "NORMAL" << "\n";
        }
    }
}

void AttendanceSystem::logPrintRemovePlayer() const {
    std::cout << "\n";
    std::cout << "Removed player\n";
    std::cout << "==============\n";
    for (int i = 1; i <= playerIdCnt; i++) {
        if (playerRemoved[i] == 1) {
            std::cout << playerNameArr[i] << "\n";
        }
    }
}

void AttendanceSystem::processAttendSystem() {
    handleInputData();
    updataBonusPoint();
    updatePlayerGrade();
    updateRemovePlayer();
    logPrintResult();
    logPrintRemovePlayer();
}