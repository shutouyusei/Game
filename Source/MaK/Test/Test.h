#pragma once
#include "CoreMinimal.h"

class TestHelper {
public:
  void Check(bool b, FString message = "");

  template <typename T> void Equal(T &a, T &b, FString message = "") {
    if (a != b) {
      Check(false, message);
    }
  };
  template <typename T> void NotNull(T *a, FString message = "") {
    if (a == nullptr) {
      Check(false, message);
    }
  }
  bool IsTest() { return isTest_; }

private:
  bool isTest_ = true;
};
