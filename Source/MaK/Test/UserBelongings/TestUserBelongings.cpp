#include "../../UserBelongings/UserBelongings/UserBelongings.h"
#include "../../UserBelongings/UserBelongings/UserBelongingsFactory.h"
#include "../Test.h"
#include "CoreMinimal.h"

bool operator==(BelongingAmount &lhs, BelongingAmount &rhs) {
  return lhs.id == rhs.id && lhs.amount == rhs.amount;
}

bool operator!=(BelongingAmount &lhs, BelongingAmount &rhs) {
  return !(lhs == rhs);
}

bool operator==(TArray<BelongingAmount> &lhs, TArray<BelongingAmount> &rhs) {
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

bool operator!=(TArray<BelongingAmount> &lhs, TArray<BelongingAmount> &rhs) {
  return !(lhs == rhs);
}

// TEST
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

// Increase
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
  TArray<BelongingAmount> correctArray = {BelongingAmount(1, 1),
                                          BelongingAmount(2, 2)};
  TArray<BelongingAmount> belongingsArray = belongings->GetBelonging();
  /* In test case UserBelongings initialized with 2 belongings { 1, 1 }, { 2, 2}
   */
  helper->Equal(correctArray, belongingsArray, TEXT("Testcase 1"));
  // testcase 2
  //
  correctArray = {BelongingAmount(1, 2), BelongingAmount(2, 2)};
  belongings->Increase(1, 1);
  belongingsArray = belongings->GetBelonging();
  helper->Equal(correctArray, belongingsArray, TEXT("Testcase 2"));
  // testcase 3
  //
  correctArray = {BelongingAmount(1, 2), BelongingAmount(2, 2),
                  BelongingAmount(3, 1)};
  belongings->Increase(3, 1);
  belongingsArray = belongings->GetBelonging();
  helper->Equal(correctArray, belongingsArray, TEXT("Testcase 3"));

  return helper->IsTest();
}

// Decrease
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
  TArray<BelongingAmount> correctArray = {BelongingAmount(1, 1),
                                          BelongingAmount(2, 2)};
  TArray<BelongingAmount> belongingsArray = belongings->GetBelonging();
  /* In test case UserBelongings initialized with 2 belongings { 1, 1 }, { 2, 2}
   */
  helper->Equal(correctArray, belongingsArray, TEXT("Testcase 1"));
  // testcase 2
  //
  correctArray = {BelongingAmount(2, 2)};
  belongings->Decrease(1, 1);
  belongingsArray = belongings->GetBelonging();
  helper->Equal(correctArray, belongingsArray, TEXT("Testcase 2"));
  // testcase 3
  //
  correctArray = {BelongingAmount(2, 1)};
  belongings->Decrease(2, 1);
  belongingsArray = belongings->GetBelonging();
  helper->Equal(correctArray, belongingsArray, TEXT("Testcase 3"));
  return helper->IsTest();
}
