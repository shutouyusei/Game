// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "MaKGameMode.generated.h"

class AMaKCharacter;
class UIManager;

UCLASS(minimalapi)
class AMaKGameMode : public AGameModeBase {
  GENERATED_BODY()

public:
  AMaKGameMode();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

private:
public:
  // UI

protected:
  AMaKCharacter *character_;
  UIManager *uiManager_;
};
