#include "Damage.h"
#include "CoreMinimal.h"
#include "DamageStruct.h"
#include "StatsBase.h"

void Damage::ApplyDamage(UStatsBase *applyier, UStatsBase *target,
                         FDamageStruct damage) {
  // Calculate damage
  if (applyier == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("Applyier is null"));
  }
  if (target == nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("Target is null"));
  }
  // calculate damage
  target->Damage(damage.power);
}
