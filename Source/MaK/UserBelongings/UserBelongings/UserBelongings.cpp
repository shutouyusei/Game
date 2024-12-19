#include "UserBelongings.h"
#include "CoreMinimal.h"
#include "../DataBase/DataBase.h"

UserBelongings::UserBelongings(TArray<Belonging> &belonging, DataBase *DataBase): belongings_(belonging), dataBase_(DataBase) {};

UserBelongings::~UserBelongings() {};

void UserBelongings::Increase(int id, int amount) {
  for (Belonging &belonging : belongings_) {
    if (id == belonging.id) {
      belonging.amount += amount;
      return;
    }
  }
  Add(id, amount);
}

void UserBelongings::Decrease(int id, int amount) {
  int index = 0;
  for (Belonging &belonging : belongings_) {
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
  belongings_.Add(Belonging(id, amount));
}

void UserBelongings::Remove(int index) { belongings_.RemoveAt(index); }

void UserBelongings::Use(int id) {}

void UserBelongings::Use(const char *name) {}
