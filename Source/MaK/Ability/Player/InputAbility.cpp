#include "InputAbility.h"
#include "Math/Vector2D.h"
#include "MyCharacter.h"

void UInputAbility::BeginPlay() {
  // Create the ability
  Ability_ = NewObject<UAbility>(this, InputAbility_);
  Ability_->SetOwner(owner_);
  Ability_->BeginPlay();
}

void UInputAbility::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Ability_->EndPlay(EndPlayReason);
  Ability_->ConditionalBeginDestroy();
}

// TEST:攻撃時に向きが変化するか
//
void UInputAbility::DoAbility() {
  // Input情報から向きを決める
  AMyCharacter *character = Cast<AMyCharacter>(owner_->GetOwner());
  if (character == nullptr)
    return;
  // Get the forward vector of the character
  FVector actorForward = character->GetActorForwardVector();
  // Get the camera forward vector
  FVector2D cameraForward = character->GetCameraForwardVector();
  // Get the move input value
  FVector2D vector = character->GetMoveInputValue();
  // Calculate angle
  float angle = FMath::Atan2(cameraForward.Y, cameraForward.X);
  // Rotate the vector
  FVector2D rotatedVector =
      FVector2D(vector.X * FMath::Cos(angle) - vector.Y * FMath::Sin(angle),
                vector.X * FMath::Sin(angle) + vector.Y * FMath::Cos(angle));
  // calculate the difference of the angle
  float diff =
      FMath::RadiansToDegrees(FMath::Atan2(rotatedVector.Y, rotatedVector.X)) -
      FMath::RadiansToDegrees(FMath::Atan2(actorForward.Y, actorForward.X));
  float MaxAngle = 45.0f;
  if (diff > MaxAngle)
    diff = MaxAngle;
  else if (diff < -MaxAngle)
    diff = -MaxAngle;
  // Set the angle
  character->SetActorRotation(FRotator(
      0.0f,
      FMath::RadiansToDegrees(FMath::Atan2(rotatedVector.Y, rotatedVector.X)) +
          diff,
      0.0f));
  // DoAbility
  Ability_->DoAbility();
}
