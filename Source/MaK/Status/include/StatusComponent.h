#pragma once
#include "../StatusParameter.h"
#include "Components/ActorComponent.h"

#include "StatusComponent.generated.h"

UCLASS()
class UStatusComponent : public UActorComponent {
  GENERATED_BODY()
public:
  UStatusComponent();
  virtual ~UStatusComponent();
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

public:
  //
  UPROPERTY(Instanced, EditAnywhere,Category = "Status")
  UStatusParameter *HP_;
  UPROPERTY(Instanced, EditAnywhere,Category = "Status")
  UStatusParameter *MP_;
  UPROPERTY(Instanced,EditAnywhere, Category = "Status")
  UStatusParameter *AD_;
  UPROPERTY(Instanced,EditAnywhere, Category = "Status")
  UStatusParameter *AP_;
  UPROPERTY(Instanced,EditAnywhere, Category = "Status")
  UStatusParameter *AR_;
  UPROPERTY(Instanced,EditAnywhere, Category = "Status")
  UStatusParameter *MR_;

private:
  float currentHP_;
  float currentMP_;
};
