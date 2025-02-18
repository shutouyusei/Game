#pragma once
#include "../StatusParameter.h"
#include "Components/ActorComponent.h"
#include "DamageStruct.h"
#include "StatusStruct.h"

#include "StatusComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UStatusComponent : public UActorComponent {
  GENERATED_BODY()
public:
  UStatusComponent();
  virtual ~UStatusComponent();
  //
  UFUNCTION(BlueprintCallable, Category = "Status")
  float GetHP();
  UFUNCTION(BlueprintCallable, Category = "Status")
  void Damage(float damage);
  UFUNCTION(BlueprintCallable, Category = "Status")
  void Heal(float heal);
  //
  UFUNCTION(BlueprintCallable, Category = "Status")
  float GetMP();
  UFUNCTION(BlueprintCallable, Category = "Status")
  bool UseMP(float mp);
  UFUNCTION(BlueprintCallable, Category = "Status")
  void RestoreMP(float mp);

protected:
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
  UPROPERTY(EditAnywhere, Category = "Status")
  FStatusStruct status_;
  //
  UPROPERTY(BlueprintReadWrite, Category = "Status")
  UStatusParameter *HP_;
  UPROPERTY(BlueprintReadWrite, Category = "Status")
  UStatusParameter *MP_;
  UPROPERTY(BlueprintReadWrite, Category = "Status")
  UStatusParameter *AD_;
  UPROPERTY(BlueprintReadWrite, Category = "Status")
  UStatusParameter *AP_;
  UPROPERTY(BlueprintReadWrite, Category = "Status")
  UStatusParameter *AR_;
  UPROPERTY(BlueprintReadWrite, Category = "Status")
  UStatusParameter *MR_;

  UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Status")
  float currentHP_;
  UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Status")
  float currentMP_;
};
