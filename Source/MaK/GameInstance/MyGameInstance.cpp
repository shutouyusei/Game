#include "MyGameInstance.h"
#include "../Character/MaKCharacter.h"
#include "../Data/Equipment/EquipmentDataBase.h"
#include "../Data/Item/ItemDataBase.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
// TODO: データベース等々静的にできる
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

AMaKCharacter *UMyGameInstance::playerCharacter = nullptr;

void UMyGameInstance::SetPlayerCharacter() {
  if (playerCharacter == nullptr) {
    playerCharacter = Cast<AMaKCharacter>(
        UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
  }
}
