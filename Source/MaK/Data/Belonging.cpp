#include "Belonging.h"

void Belongings::increaseBelongings(int id, int num) {
  for (FBelonging &belonging : belongings) {
    if (id == belonging.id) {
      belonging.num += num;
      return;
    }
  }
  addBelongings(id, num);
}

void Belongings::decreaseBelongings(int id, int num) {
  int index = 0;
  for (FBelonging &belonging : belongings) {
    if (id == belonging.id) {
      if (num < belonging.num) {
        belonging.num -= num;
      } else {
        removeBelongings(index);
      }
      return;
    }
    index++;
  }
}

void Belongings::addBelongings(int id, int num) {
  belongings.Add(FBelonging(id, num));
}

void Belongings::removeBelongings(int index) { belongings.RemoveAt(index); }

const FBelonging Belongings::getBelonging(int id) const {
  for (const FBelonging belonging : belongings) {
    if (id == belonging.id) {
      return belonging;
    }
  }
  return FBelonging();
}
