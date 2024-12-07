// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "../UI/WBItem.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "MaKGameMode.generated.h"

class AMakCharacter;

UCLASS(minimalapi)
class AMaKGameMode : public AGameModeBase {
  GENERATED_BODY()

public:
  AMaKGameMode();
  void SetItemUI();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

private:
public:
  // UI

protected:
  AMaKCharacter *character;
};
