#include "Belonging.h"

void UserBelongings::IncreaseBelongings(int id, int num) {
  for (Belonging &belonging : userBelongings_) {
    if (id == belonging.id) {
      belonging.num += num;
      return;
    }
  }
  AddBelongings(id, num);
}

void UserBelongings::DecreaseBelongings(int id, int num) {
  int index = 0;
  for (Belonging &belonging : userBelongings_) {
    if (id == belonging.id) {
      if (num < belonging.num) {
        belonging.num -= num;
      } else {
        RemoveBelongings(index);
      }
      return;
    }
    index++;
  }
  UE_LOG(LogTemp, Warning, TEXT("[Belongings]DecreaseBelongings: fail"));
}

void UserBelongings::AddBelongings(int id, int num) {
  userBelongings_.Add(Belonging(id, num));
}

void UserBelongings::RemoveBelongings(int index) {
  userBelongings_.RemoveAt(index);
}
