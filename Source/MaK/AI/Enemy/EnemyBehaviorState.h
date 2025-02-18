#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, Blueprintable)
enum class EEnemyBehaiviorState : uint8 {
  Idle UMETA(DisplayName = "Idle"),
  Combat UMETA(DisplayName = "Combat"),
};
