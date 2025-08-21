#include "gmock/gmock.h"
#include "attendance.h"

using namespace testing;

class MockAttendanceSystem : public AttendanceSystem {
public:
    //MOCK_METHOD(void, setPlayerId, (const std::string& playerName), (override));

};

class AttendTestFixture : public Test {
public:
    void SetUp() override {}
    void TearDown() override {}
protected:
    AttendanceSystem system;
};

TEST_F(AttendTestFixture, TC1_setplayer) {
    std::map<std::string, int> m = { {"Umar", 1}, {"Daisy", 2} };
    system.setPlayerIdMap(m);
    EXPECT_EQ(system.getPlayerIdMap().at("Umar"), 1);
    EXPECT_EQ(system.getPlayerIdMap().at("Daisy"), 2);
}

TEST_F(AttendTestFixture, TC2_PlayerIdCnt) {
    system.setPlayerIdCnt(5);
    EXPECT_EQ(system.getPlayerIdCnt(), 5);
}

TEST_F(AttendTestFixture, TC3_PlayerName) {
    system.setPlayerName(0, "Umar");
    EXPECT_EQ(system.getPlayerName(0), "Umar");
}

TEST_F(AttendTestFixture, TC4_PlayerPoint) {
    system.setPlayerPoint(0, 10);
    EXPECT_EQ(system.getPlayerPoint(0), 10);
}

TEST_F(AttendTestFixture, TC5_PlayerRemoved) {
    system.setPlayerRemoved(0, 1);
    EXPECT_EQ(system.getPlayerRemoved(0), 1);
}

TEST_F(AttendTestFixture, TC6_PlayerGrade) {
    system.setPlayerGrade(0, AttendanceSystem::GOLD);
    EXPECT_EQ(system.getPlayerGrade(0), AttendanceSystem::GOLD);
}

TEST_F(AttendTestFixture, TC7_AttendCntDayById) {
    system.setAttendCntDayById(0, 1, 3);
    EXPECT_EQ(system.getAttendCntDayById(0, 1), 3);
}

TEST_F(AttendTestFixture, TC8_AttendCntWednesday) {
    system.setAttendCntWednesday(0, 2);
    EXPECT_EQ(system.getAttendCntWednesday(0), 2);
}

TEST_F(AttendTestFixture, TC9_AttendCntWeekend) {
    system.setAttendCntWeekend(0, 4);
    EXPECT_EQ(system.getAttendCntWeekend(0), 4);
}

TEST_F(AttendTestFixture, TC10_ArrDayOfWeek) {
    system.setArrDayOfWeek(0, "monday");
    EXPECT_EQ(system.getArrDayOfWeek(0), "monday");
}

TEST_F(AttendTestFixture, TC11_IsRemovePlayer) {
    system.setPlayerRemoved(0, 1);
    EXPECT_TRUE(system.isRemovePlayer(0));
}
TEST_F(AttendTestFixture, TC12_IsRemovePlayer_false) {
    system.setPlayerRemoved(0, 0);
    EXPECT_TRUE(system.isRemovePlayer(0));
}

TEST_F(AttendTestFixture, TC13_PlayerId) {
    //EXPECT_CALL(system, setPlayerId("Umar")).Times(1);
    system.setPlayerId("Umar");
}

TEST_F(AttendTestFixture, CallUpdateRemovePlayer) {
    system.updateRemovePlayer();
}

TEST_F(AttendTestFixture, TC14_UpdataBonusPoint) {
    system.updataBonusPoint();
}

TEST_F(AttendTestFixture, TC15_UpdatePlayerGrade) {
    system.updatePlayerGrade();
}

TEST_F(AttendTestFixture, TC16_HandleInputData) {
    system.handleInputData();
}

TEST_F(AttendTestFixture, TC17_IncreasePoint) {
    system.increasePoint(0, "monday");
}

TEST_F(AttendTestFixture, TC18_SetAttendCntDaybyId) {
    system.setAttendCntDaybyId(0, "monday");
}

TEST_F(AttendTestFixture, TC19_ProcessAttendSystem) {
    system.processAttendSystem();
}

TEST_F(AttendTestFixture, TC20_LogPrintResult) {
    system.logPrintResult();
}

TEST_F(AttendTestFixture, TC21_LogPrintRemovePlayer) {
    system.logPrintRemovePlayer();
}

TEST_F(AttendTestFixture, TC22_GetPlayerName) {
    system.setPlayerName(99, "Tmpp");
    EXPECT_EQ(system.getPlayerName(99), "Tmpp");
}

TEST_F(AttendTestFixture, TC23_GetPlayerPoint) {
    system.setPlayerPoint(44, 123);
    EXPECT_EQ(system.getPlayerPoint(44), 123);
}

TEST_F(AttendTestFixture, TC24_GetPlayerRemoved) {
    system.setPlayerRemoved(44, 1);
    EXPECT_EQ(system.getPlayerRemoved(44), 1);
}

TEST_F(AttendTestFixture, TC25_GetPlayerGrade) {
    system.setPlayerGrade(44, AttendanceSystem::SILVER);
    EXPECT_EQ(system.getPlayerGrade(44), AttendanceSystem::SILVER);
}

TEST_F(AttendTestFixture, TC26_GetAttendCntDayById) {
    system.setAttendCntDayById(44, 44, 7);
    EXPECT_EQ(system.getAttendCntDayById(44, 44), 7);
}

TEST_F(AttendTestFixture, TC27_GetAttendCntWednesday) {
    system.setAttendCntWednesday(44, 8);
    EXPECT_EQ(system.getAttendCntWednesday(44), 8);
}

TEST_F(AttendTestFixture, TC28_GetAttendCntWeekend) {
    system.setAttendCntWeekend(44, 9);
    EXPECT_EQ(system.getAttendCntWeekend(44), 9);
}

TEST_F(AttendTestFixture, TC29_GetArrDayOfWeek) {
    system.setArrDayOfWeek(6, "sunday");
    EXPECT_EQ(system.getArrDayOfWeek(6), "sunday");
}

TEST_F(AttendTestFixture, TC30_Enum) {
    EXPECT_EQ(AttendanceSystem::GOLD, 1);
    EXPECT_EQ(AttendanceSystem::SILVER, 2);
    EXPECT_EQ(AttendanceSystem::NORMAL, 3);
}
