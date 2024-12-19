#include "../../UserBelongings/UserBelongings/UserBelongings.h"
#include "../../UserBelongings/UserBelongings/UserBelongingsFactory.h"
#include "../Test.h"
#include "CoreMinimal.h"

bool operator==(Belonging &lhs, Belonging &rhs) {
  return lhs.id == rhs.id && lhs.amount == rhs.amount;
}

bool operator!=(Belonging &lhs, Belonging &rhs) { return !(lhs == rhs); }

bool operator==(TArray<Belonging> &lhs, TArray<Belonging> &rhs) {
  if (lhs.Num() != rhs.Num()) {
    return false;
  }
  for (int i = 0; i < lhs.Num(); i++) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(TArray<Belonging> &lhs, TArray<Belonging> &rhs) {
  return !(lhs == rhs);
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUserBelongingsTest,
                                 "UserBelongings.FactoryTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FUserBelongingsTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();
  UserBelongingsFactory *factory = new UserBelongingsFactory();
  helper->NotNull(factory->CreateBelongings());
  return helper->IsTest();
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUserBelongingsIncreaseTest,
                                 "UserBelongings.IncreaseTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FUserBelongingsIncreaseTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();

  UserBelongingsFactory *factory = new UserBelongingsFactory();
  UserBelongings *belongings = factory->CreateBelongings();
  // testcase 1
  //
  TArray<Belonging> correctArray = {Belonging(1, 1), Belonging(2, 2)};
  TArray<Belonging> belongingsArray = belongings->GetBelonging();
  /* In test case UserBelongings initialized with 2 belongings { 1, 1 }, { 2, 2}
   */
  helper->Equal(correctArray, belongingsArray);
  // testcase 2
  //
  correctArray = {Belonging(1, 2), Belonging(2, 2)};
  belongings->Increase(1, 1);
  helper->Equal(correctArray, belongingsArray);
  // testcase 3
  //
  correctArray = {Belonging(1, 2), Belonging(2, 2), Belonging(3, 1)};
  belongings->Increase(3, 1);
  helper->Equal(correctArray, belongingsArray);

  return helper->IsTest();
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUserBelongingsDecreaseTest,
                                 "UserBelongings.DecreaseTest",
                                 EAutomationTestFlags::EditorContext |
                                     EAutomationTestFlags::EngineFilter)
bool FUserBelongingsDecreaseTest::RunTest(const FString &Parameters) {
  TestHelper *helper = new TestHelper();
  UserBelongingsFactory *factory = new UserBelongingsFactory();
  UserBelongings *belongings = factory->CreateBelongings();
  // testcase 1
  //
  TArray<Belonging> correctArray = {Belonging(1, 1), Belonging(2, 2)};
  TArray<Belonging> belongingsArray = belongings->GetBelonging();
  /* In test case UserBelongings initialized with 2 belongings { 1, 1 }, { 2, 2}
   */
  helper->Equal(correctArray, belongingsArray);
  // testcase 2
  //
  correctArray = {Belonging(2, 2)};
  belongings->Decrease(1, 1);
  helper->Equal(correctArray, belongingsArray);
  // testcase 3
  //
  correctArray = {Belonging(2, 1)};
  belongings->Decrease(2, 1);
  helper->Equal(correctArray, belongingsArray);
  return helper->IsTest();
}
