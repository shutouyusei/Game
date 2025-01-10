#pragma once
#include "../Ability.h"
#include "MyCharacter.h"

class UAnimMontage;

class MyAbility : public Ability {
public:
  MyAbility(AMyCharacter *character);
  ~MyAbility() override;
  void DoAbility() = 0;

protected:
  void PlayMontage(UAnimMontage *montage);
  void StopMontage(UAnimMontage *montage);
  AMyCharacter *character_;
};
