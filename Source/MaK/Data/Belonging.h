#pragma once

#include "CoreMinimal.h"

struct Belonging {
  int id;
  int num;
};

class UserBelongings {
public:
  // Set
  // setはアイテムの増減のみで許される
  void IncreaseBelongings(int id, int num);
  void DecreaseBelongings(int id, int num);
  // Get

  TArray<Belonging> userBelongings_;

private:
  void AddBelongings(int id, int num);
  void RemoveBelongings(int index);

private:
};
