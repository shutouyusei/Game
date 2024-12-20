#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"

#include "MyGameInstance.generated.h"

UCLASS()
class MAK_API UMyGameInstance : public UGameInstance {
  GENERATED_BODY()
public:
  void Init() override;
  void Shutdown() override;
  //
  FStreamableManager *GetStreamableManager() { return &streamableManager_; };

private:
public:
private:
  FStreamableManager streamableManager_;
  // static instance
  static UMyGameInstance *instance_;
};
