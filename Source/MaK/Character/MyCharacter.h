#pragma once
#include "MaKCharacter.h"

#include "MyCharacter.generated.h"

UCLASS()
class AMyCharacter : public AMaKCharacter {
  GENERATED_BODY()
protected:
  void BeginPlay() override;
  void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
