#pragma once

#include "Animation/AnimInstance.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "MontagePlayer.generated.h"

class UAnimMontage;

UCLASS()
class UMontagePlayer : public UObject {
  GENERATED_BODY()
public:
  void PlayMontage(UAnimInstance *anim_instance,FOnMontageEnded delegate);

private:
  UPROPERTY(EditAnywhere, Category = "Default")
  UAnimMontage *montage_;
};
