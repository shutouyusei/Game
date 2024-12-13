#pragma once

#include "../Belonging.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "ItemComponent.generated.h"

class UItemDataBase;
class AMaKCharacter;
class UseItemHandler;
struct FBelonging;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAK_API UItemComponent : public UActorComponent {
  GENERATED_BODY()
public:
  // setup
  UItemComponent();
  void SetUpItemComponent(AMaKCharacter *character);
  ~UItemComponent();
  // BeginPlay
  void BeginPlay() override;
  // setupbelongings
  void SetUpBelongings();
  // get belongings
  Belongings *GetBelongings() { return belongings_; }
  // Use
  void UseItem(const int id);

private:
private:
  Belongings *belongings_;
  UItemDataBase *itemDataBase_;
  TObjectPtr<AMaKCharacter> owner_;
  UseItemHandler *useItemHandler_;
};
