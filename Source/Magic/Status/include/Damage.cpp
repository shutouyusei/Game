#include "Damage.h"

float UDamage::CalculateDamage(UStatusComponent *applyier,
                               UStatusComponent *target, FDamageStruct damage) {
  // Caluculate damage
  float calculatedDamage = damage.power;

  return calculatedDamage;
}

void UDamage::ApplyDamage(UStatusComponent *applyier, UStatusComponent *target,
                          FDamageStruct damage) {
  // Apply damage
  float calculatedDamage = CalculateDamage(applyier, target, damage);
  UE_LOG(LogTemp, Warning, TEXT("Damage: %f"), calculatedDamage);
  target->Damage(calculatedDamage);
}
