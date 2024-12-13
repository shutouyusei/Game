#include "Belonging.h"

void Belongings::IncreaseBelongings(int id, int num) {
  for (FBelonging &belonging : belongings) {
    if (id == belonging.id) {
      belonging.num += num;
      return;
    }
  }
  AddBelongings(id, num);
}

void Belongings::DecreaseBelongings(int id, int num) {
  int index = 0;
  for (FBelonging &belonging : belongings) {
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

void Belongings::AddBelongings(int id, int num) {
  belongings.Add(FBelonging(id, num));
}

void Belongings::RemoveBelongings(int index) { belongings.RemoveAt(index); }
