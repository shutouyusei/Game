#include "Damage.h"
#include "CoreMinimal.h"
#include "StatsBase.h"

void Damage::ApplyDamage(StatsBase *applyier, StatsBase *target, float damage) {
  // Calculate damage
  if (applyier == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("Applyier is null"));
  }
  if (target == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("Target is null"));
  }
  UE_LOG(LogTemp, Warning, TEXT("Damage: %f"), damage);
  // calculate damage
  target->HP_.Damage(damage);
}
