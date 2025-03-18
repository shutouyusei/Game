#include "InputAbilityModifier.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Vector2D.h"
#include "MyCharacter.h"

void UInputAbilityModifier::AbilityMod(UAbilityManager *manager) {
  AMyCharacter *character = Cast<AMyCharacter>(manager->GetOwner());
  if (character == nullptr)
    return;
  // Set the angle
  FVector2D input = character->GetMoveInputValue();
  if (input.Size() > 0.1f) {
    float angle = CalcuateMoveRadians(character, input);
    character->SetActorRotation(FRotator(0.0f, angle, 0.0f));
  }
}

// 入力方向への回転をする
// この方が操作が直感的
float UInputAbilityModifier::CalcuateMoveRadians(AMyCharacter *character, FVector2D input) {
  // Calculate the move direction
  input = {-input.X, input.Y};
  // Get the camera forward vector
  FVector2D cameraForward = character->GetCameraForwardVector();
  // calculate
  FVector2D moveDirection = input.GetRotated(
      -FMath::RadiansToDegrees(FMath::Atan2(cameraForward.X, cameraForward.Y)));
  // Check actor forward and move direction
  return FMath::RadiansToDegrees(FMath::Atan2(moveDirection.Y, moveDirection.X));
}
