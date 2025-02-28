#include "InputAbility.h"
#include "Math/UnrealMathUtility.h"
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

void UInputAbility::DoAbility() {
  // Input情報から向きを決める
  AMyCharacter *character = Cast<AMyCharacter>(owner_->GetOwner());
  if (character == nullptr)
    return;
  // Get the move input value
  FVector2D input = character->GetMoveInputValue();
  if (input.Size() > 0.1f) {
    input = {-input.X, input.Y};
    // Get the forward vector of the character
    FVector actorForward = character->GetActorForwardVector();
    // Get the camera forward vector
    FVector2D cameraForward = character->GetCameraForwardVector();

    // calculate
    FVector2D moveDirection = input.GetRotated(-FMath::RadiansToDegrees(
        FMath::Atan2(cameraForward.X, cameraForward.Y)));
    // Set the angle
    character->SetActorRotation(FRotator(
        0.0f,
        FMath::RadiansToDegrees(FMath::Atan2(moveDirection.Y, moveDirection.X)),
        0.0f));
  }
  // DoAbility
  Ability_->DoAbility();
}
