#pragma once
#include "../../../SkillFactory.h"

#include "NormalSwordAttackFactory.generated.h"

class UAnimatedAttackFactory;
class UAnimatedAttack;
struct FDamageInfo;

UCLASS()
class UNormalSwordAttackFactory : public USkillFactory {
  GENERATED_BODY()
public:
  USkill *Create(int32 level, USkillManager *manager) override;

private:
  UAnimatedAttack *CreateAttackModules(int32 level, USkillManager *manager, UAnimatedAttackFactory *attack_factory, UAnimMontage *montage);

private:
  UPROPERTY(EditAnywhere)
  TArray<UAnimMontage *> montages_on_ground_;
  UPROPERTY(EditAnywhere)
  TArray<UAnimMontage *> montages_in_air_;
};
