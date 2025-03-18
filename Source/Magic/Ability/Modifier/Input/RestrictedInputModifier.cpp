#include "Math/UnrealMathUtility.h"
#include "Math/Vector2D.h"
#include "MyCharacter.h"
#include "RestrictedInputAbilityModifier.h"

void URestrictedInputAbilityModifier::AbilityMod(UAbilityManager *manager) {
  // Input情報から向きを決める
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

// XXX:より効率よいプログラムがあれば考える
float URestrictedInputAbilityModifier::CalcuateMoveRadians(AMyCharacter *character, FVector2D input) {
  // Calculate the move direction
  // Get the forward vector of the character
  FVector actor_forward = character->GetActorForwardVector();
  input = {-input.X, input.Y};
  // Get the camera forward vector
  FVector2D camera_forward = character->GetCameraForwardVector();
  // calculate
  FVector2D move_direction = input.GetRotated(-FMath::RadiansToDegrees(FMath::Atan2(camera_forward.X, camera_forward.Y)));
  // Check actor forward and move direction
  float angle_radians = FMath::Atan2(
      actor_forward.X * move_direction.Y - actor_forward.Y * move_direction.X,
      actor_forward.X * move_direction.X + actor_forward.Y * move_direction.Y);

  if (angle_radians > FMath::DegreesToRadians(15.0f) || angle_radians < FMath::DegreesToRadians(-180.0f)) {
    float actorAngle = FMath::RadiansToDegrees(FMath::Atan2(actor_forward.Y, actor_forward.X));
    return 15.0f + actorAngle;
    //
  } else if (angle_radians < FMath::DegreesToRadians(-15.0f) || angle_radians > FMath::DegreesToRadians(180.0f)) {
    float actorAngle = FMath::RadiansToDegrees(FMath::Atan2(actor_forward.Y, actor_forward.X));
    return -15.0f + actorAngle;
    //
  } else {
    return FMath::RadiansToDegrees(FMath::Atan2(move_direction.Y, move_direction.X));
    //
  }
}
