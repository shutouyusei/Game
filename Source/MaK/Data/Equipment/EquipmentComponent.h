#pragma once

#include "../Have.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "EquipmentComponent.generated.h"

class UEquipmentDataBase;
class AMaKCharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAK_API UEquipmentComponent : public UActorComponent {
  GENERATED_BODY()
public:
  UEquipmentComponent();
  void SetOwner(AMaKCharacter *character) { this->owner = character; }
  TArray<FHave> GetHaveEquipments() { return haveEquipments; }
  void AddEquipment(const int id, const int num);
  void RemoveEquipment(const int id, const int num);

private:
  UEquipmentDataBase *GetEquipmentDataBase();

public:
private:
  TArray<FHave> haveEquipments;
  TObjectPtr<AMaKCharacter> owner;
};
