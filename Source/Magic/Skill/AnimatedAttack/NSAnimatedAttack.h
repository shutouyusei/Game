#pragma once
#include "AnimatedAttack.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"

#include "NSAnimatedAttack.generated.h"

class UAnimatedAttack;

UCLASS()
class UNSAnimatedAttack : public UAnimNotifyState {
  GENERATED_BODY()
public:
  void NotifyBegin(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float TotalDuration) override;
  void NotifyTick(USkeletalMeshComponent *MeshComp, UAnimSequenceBase *Animation, float FrameDeltaTime) override;

private:
  void PerformTrace(USkeletalMeshComponent *mesh);
  void OnAttack(ACharacter *target);

public:
  UPROPERTY()
  TObjectPtr<UAnimatedAttack> attack_module_;

private:
  UPROPERTY(EditAnywhere)
  float reach_ = 1000.0f;
  UPROPERTY(EditAnywhere)
  float radius_ = 10.0f;
  UPROPERTY(EditAnywhere)
  FName socket_name_;
  UPROPERTY()
  TArray<TObjectPtr<ACharacter>> targets_;
};
