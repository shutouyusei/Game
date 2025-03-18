#pragma once
#include "CoreMinimal.h"
#include "DamageStruct.h"
#include "UObject/NoExportTypes.h"

#include "AttackWithMontage.generated.h"
class UAnimMontage;
class AAttackCollision;

UCLASS(EditInlineNew, BlueprintType)
class UAttackWithMontage : public UObject {
  GENERATED_BODY()
public:
  void AttackWithMontage(FOnMontageEnded delegate, AAttackCollision *attack_collision, AActor *applyier);
  void EndAttack(AAttackCollision *attack_collision);

private:
  void OnMontageEnded(UAnimMontage *montage, bool interrupted);

public:
  UPROPERTY(EditAnywhere, Category = "Default")
  TObjectPtr<UAnimMontage> montage_;
  UPROPERTY(EditAnywhere, Category = "Default")
  FDamageStruct damage_;
};
