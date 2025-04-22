#pragma once
#include "../../Notify/SkillNotify.h"
#include "../../SkillFactory.h"

#include "AnimatedAttackSkillFactory.generated.h"

class UAnimatedAttack;
struct FDamageInfo;

UCLASS()
class UAnimatedAttackSkillFactory : public USkillFactory {
  GENERATED_BODY()
private:
  USkillNotify *get_skill_notify(UAnimatedAttack *attack_module);
protected:
  UAnimatedAttack *CreateAttackModule(USkillManager *manager, UAnimMontage *montage, FDamageInfo damage_info);
  FDamageInfo CreateDamageInfo(int32 level);
  template<typename T>
  void SetSkillEffect(UAnimatedAttack *attack_module,T *object,void (T::* function)(void)){
    USkillNotify *skill_notify = get_skill_notify(attack_module);
    if(skill_notify){
      skill_notify->skill_effect_.BindUObject(object,function);
    }
  };

};
