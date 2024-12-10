#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "ItemComponent.generated.h"

class UItemDataBase;
class Belongings;
class AMaKCharacter;
class Item;
struct FBelonging;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAK_API UItemComponent : public UActorComponent {
  GENERATED_BODY()
public:
  // setup
  UItemComponent();
  ~UItemComponent();
  void BeginPlay() override;
  void SetUpItemComponent(AMaKCharacter *character);
  // Use
  void UseItem(const int id);

private:
public:
  Belongings *belongings_;

private:
  UItemDataBase *itemDataBase_;
  TObjectPtr<AMaKCharacter> owner_;
  Item *useableItem_;
};
