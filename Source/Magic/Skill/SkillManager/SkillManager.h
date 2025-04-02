#pragma once
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "SkillManager.generated.h"

class USkillFactory;
class USkill;
class USkillExecutionManager;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class USkillManager final : public UActorComponent {
  GENERATED_BODY()
public:
  USkillManager();

private:
  void BeginPlay() override;
  void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
  UPROPERTY()
  TObjectPtr<USkillExecutionManager> execution_manager_;

private:
  UPROPERTY()
  TArray<USkillFactory *> skill_factories_;
  UPROPERTY()
  TArray<USkill *> skills_;
};
