#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"

#include "AbilityNotify.generated.h"

UCLASS()
class UAbilityNotify : public UAnimNotifyState {
  GENERATED_BODY()
public:
  UAbilityNotify();
  ~UAbilityNotify();
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Notify")
  FName Name;

  void NotifyBegin(USkeletalMeshComponent *MeshComp,
                   UAnimSequenceBase *Animation, float TotalDuration) override;
  void NotifyEnd(USkeletalMeshComponent *MeshComp,
                 UAnimSequenceBase *Animation) override;

  void SetDelegate(std::function<void()> beginDelegate,
                   std::function<void()> endDelegate);

private:
  std::function<void()> beginDelegate_;
  std::function<void()> endDelegate_;
};
