#pragma once
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CoreMinimal.h"

#include "AbilityNotify.generated.h"

UCLASS(Blueprintable)
class UAbilityNotify : public UAnimNotifyState {
  GENERATED_BODY()
public:
  UAbilityNotify();
  ~UAbilityNotify();

  void SetDelegate(std::function<void()> beginDelegate,
                   std::function<void()> endDelegate);

protected:
  void NotifyBegin(USkeletalMeshComponent *MeshComp,
                   UAnimSequenceBase *Animation, float TotalDuration) override;
  void NotifyEnd(USkeletalMeshComponent *MeshComp,
                 UAnimSequenceBase *Animation) override;

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Notify")
  FName Name;

private:
  std::function<void()> beginDelegate_;
  std::function<void()> endDelegate_;
};
// TODO:複数アビリティを定義できないので修正sする
