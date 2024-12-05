#pragma once

#include "../Have.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "ItemComponent.generated.h"

class UItemDataBase;
class AMaKCharacter;
class Item;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAK_API UItemComponent : public UActorComponent {
  GENERATED_BODY()
public:
  // setup
  UItemComponent();
  ~UItemComponent();
  void SetOwner(AMaKCharacter *character) { this->owner = character; }
  void CreateItemObject(AMaKCharacter *character);
  TArray<FHave> GetHaveItems() { return haveItems; }
  // use
  void IncreaseItem(const int id, const int num);
  void AddItem(const int id, const int num);
  void DecreaseItem(const int id, const int num);
  void RemoveItem(const int id);

  void UseItem(const int id);
  void UseAbilityBook(const int id);

private:
  UItemDataBase *GetItemDataBase();

public:
private:
  TArray<FHave> haveItems;
  TObjectPtr<AMaKCharacter> owner;
  Item *itemInstance;
};
