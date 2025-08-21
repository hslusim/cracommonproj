#include "attendance.h"

void initAttendanceData(string playerName, string dayOfWeek) {
    setPlayerId(playerName);
    setAttendCntDaybyId(playerIdMap[playerName], dayOfWeek);
    increasePoint(playerIdMap[playerName], dayOfWeek);
}

inline void increasePoint(int targetId, string dayOfWeek)
{
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
    else { playerPoint[targetId] += 1; }
}

void setAttendCntDaybyId(int targetId, string& dayOfWeek)
{
    if (targetId > playerIdCnt) {
        cout << "Invalid player ID" << endl;
        return;
    }

    for (int i = 0; i < 7; i++) {
        if (arrDayOfWeek[i].compare(dayOfWeek) == 0) {
            attendCntDayById[targetId][i] += 1;
            break;
        }
    }
}

void setPlayerId(std::string& playerName)
{
    if (playerIdMap.count(playerName) == 0) {
        playerIdMap.insert({ playerName, ++playerIdCnt });
        playerNameArr[playerIdCnt] = playerName;
    }
}

void processAttendSystem()
{
    handleInputData();
    updataBonusPoint();
    updatePlayerGrade();
    updateRemovePlayer();
    logPrintResult();
    logPrintRemovePlayer();
}

void logPrintRemovePlayer()
{
    std::cout << "\n";
    std::cout << "Removed player\n";
    std::cout << "==============\n";
    for (int i = 1; i <= playerIdCnt; i++) {

        if (playerRemoved[i] == 1) {
            std::cout << playerNameArr[i] << "\n";
        }
    }
}

void updateRemovePlayer()
{
    for (int i = 1; i <= playerIdCnt; i++) {

        if (isRemovePlayer(i)) {
            playerRemoved[i] = 1;
        }
    }
}

bool isRemovePlayer(int i)
{
    return playerGrade[i] != GOLD && playerGrade[i] != SILVER && attendCntWednesday[i] == 0 && attendCntWeekend[i] == 0;
}

void logPrintResult()
{
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

void updataBonusPoint()
{
    for (int i = 1; i <= playerIdCnt; i++) {
        if (attendCntDayById[i][2] > 9) {
            playerPoint[i] += 10;
        }

        if (attendCntDayById[i][5] + attendCntDayById[i][6] > 9) {
            playerPoint[i] += 10;
        }
    }
}

void updatePlayerGrade()
{
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

void handleInputData()
{
    ifstream fin{ "attendance_weekday_500.txt" };
    for (int i = 0; i < MAX_ATTENDANCE_DATA_LEN; i++) {
        string playerName, dayOfWeek;
        fin >> playerName >> dayOfWeek;
        initAttendanceData(playerName, dayOfWeek);
    }
}

int main() {
    if (0)
    {
        testing::InitGoogleMock();
        return RUN_ALL_TESTS();
    }
    else
    {
        processAttendSystem();
    }
}
