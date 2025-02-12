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
  target->Damage(calculatedDamage);
}
