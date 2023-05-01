#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Awards.h"
using awards::RankList;
using awards::AwardCeremonyActions;
using::testing::InSequence;

// TEST(TriangleTests, testPerimeter) {
//     Triangle *aTriangle = new Triangle(3,3,3);
//     EXPECT_EQ (aTriangle->getPerimeter(),9);
// }

class DerivedRankList:public RankList {
    public:
        std::string getNext()
        {
            counter++;
            return people[counter];
        }
    private:
        std::string people[3] = {"Mickey", "Donald", "Goofy"};
        int counter = -1;
};

class MockAwardCeremonyActions:public AwardCeremonyActions {
    public:
        MOCK_METHOD(void, playAnthem, (), (override));
        MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
        MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
        MOCK_METHOD(void, awardGold, (std::string recipient), (override));
        MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
};

TEST(AwardsTests, testPerformAwardCeremony) {
    MockAwardCeremonyActions myRewards;
    DerivedRankList myRanks;
    
    InSequence seq;

    EXPECT_CALL (myRewards, playAnthem());
    EXPECT_CALL (myRewards, awardBronze("Mickey"));
    EXPECT_CALL (myRewards, awardSilver("Donald"));
    EXPECT_CALL (myRewards, awardGold("Goofy"));
    EXPECT_CALL (myRewards, turnOffTheLightsAndGoHome());
 
    performAwardCeremony(myRanks, myRewards);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

