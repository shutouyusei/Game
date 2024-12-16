#include "MyGameInstance.h"
#include "../Character/MaKCharacter.h"
#include "../Data/Equipment/EquipmentDataBase.h"
#include "../Data/Item/ItemDataBase.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// init static variable
UMyGameInstance *UMyGameInstance::instance_ = nullptr;

// TODO: データベース等々静的にできる
void UMyGameInstance::Init() {
  UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance"));
  instance_ = this;
  SetDataBase();
  SetPlayerCharacter();
}

void UMyGameInstance::Shutdown() {}

void UMyGameInstance::SetDataBase() {
  itemDataBase_ = NewObject<UItemDataBase>();
  itemDataBase_->BeginPlay(this);
  equipmentDataBase_ = NewObject<UEquipmentDataBase>();
  equipmentDataBase_->BeginPlay(this);
}
void UMyGameInstance::SetPlayerCharacter() {
  if (playerCharacter_ == nullptr) {
    playerCharacter_ = Cast<AMaKCharacter>(
        UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
  }
}

UMyGameInstance *UMyGameInstance::GetInstance() {
  return UMyGameInstance::instance_;
}
