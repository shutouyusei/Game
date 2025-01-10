#pragma once
#include "../MyAbility.h"

class MyCharacterNormalAttack : public MyAbility {
public:
  MyCharacterNormalAttack(AMyCharacter *character);
  ~MyCharacterNormalAttack() override;
  void DoAbility() override;

private:
  UAnimMontage *attack1_;
  int attackCount_;
};
