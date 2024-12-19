#include "Test.h"

void TestHelper::Check(bool b ,FString message) {
    if(b == false){
      isTest_ = false;
      UE_LOG(LogTemp, Error, TEXT("%s"), *message);
      if(isTest_ == true){
        isTest_ = false;
      }
    }
}
