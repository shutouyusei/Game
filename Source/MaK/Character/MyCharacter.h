#pragma once
#include "MaKCharacter.h"

#include "MyCharacter.generated.h"

UCLASS()
class AMyCharacter : public AMaKCharacter {
  GENERATED_BODY()
public:
  AMyCharacter();
  ~AMyCharacter();
protected:
  virtual void BeginPlay() override;
  virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
