#include "MyCharacterNormalAttack.h"
#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

MyCharacterNormalAttack::MyCharacterNormalAttack(AMyCharacter *character)
    : MyAbility(character) {
  // Load Montage
  attack1_ = LoadObject<UAnimMontage>(
      nullptr, TEXT("/Game/MyAbility/Montage/AM_Attack1.AM_Attack1"));
}

MyCharacterNormalAttack::~MyCharacterNormalAttack() {}

void MyCharacterNormalAttack::DoAbility() {
  switch (attackCount_) {
    case 0:
      PlayMontage(attack1_);
      break;
    case 1:
      PlayMontage(attack1_);
      break;
    case 2:
      PlayMontage(attack1_);
      break;
    case 3:
      PlayMontage(attack1_);
      break;
    default:
      break;
  }
} 
