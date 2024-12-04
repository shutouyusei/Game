#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../Data/Equipment/EquipmentDataBase.h"
#include "../Data/Item/ItemDataBase.h"
#include "Engine/Engine.h"

void UMyGameInstance::Init() {
  UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance"));
  SetDataBase();
}
void UMyGameInstance::SetDataBase() {
  itemDataBase = NewObject<UItemDataBase>();
  itemDataBase->BeginPlay(this);
  equipmentDataBase = NewObject<UEquipmentDataBase>();
  equipmentDataBase->BeginPlay(this);
}

void UMyGameInstance::Shutdown() {}

UMyGameInstance *UMyGameInstance::GetInstance() {
  UMyGameInstance *instance = nullptr;
  if (GEngine) {
    FWorldContext *context =
        GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
    instance = Cast<UMyGameInstance>(context->OwningGameInstance);
  }
  return instance;
}

