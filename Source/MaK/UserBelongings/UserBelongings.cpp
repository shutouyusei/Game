#include "UserBelongings.h"
#include "CoreMinimal.h"

UserBelongings::UserBelongings(TArray<BelongingAmount> &belonging)
    : belongingAmount_(belonging) {};

UserBelongings::~UserBelongings() {};

void UserBelongings::Increase(int id, int amount) {
  for (BelongingAmount &belonging : belongingAmount_) {
    if (id == belonging.id) {
      belonging.amount += amount;
      return;
    }
  }
  Add(id, amount);
}

void UserBelongings::Decrease(int id, int amount) {
  int index = 0;
  for (BelongingAmount &belonging : belongingAmount_) {
    if (id == belonging.id) {
      if (amount < belonging.amount) {
        belonging.amount -= amount;
      } else {
        Remove(index);
      }
      return;
    }
    index++;
  }
}

void UserBelongings::Add(int id, int amount) {
  belongingAmount_.Add(BelongingAmount(id, amount));
}

void UserBelongings::Remove(int index) { belongingAmount_.RemoveAt(index); }
