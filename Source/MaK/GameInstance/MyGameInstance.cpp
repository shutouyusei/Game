#include "MyGameInstance.h"
#include "../Character/MaKCharacter.h"
#include "../Data/Equipment/EquipmentDataBase.h"
#include "../Data/Item/ItemComponent.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// init static variable
UMyGameInstance *UMyGameInstance::instance_ = nullptr;

void UMyGameInstance::Init() {
  UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance"));
  instance_ = this;
  SetDataBase();
  SetPlayerCharacter();
  SetItemComponent();
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
void UMyGameInstance::SetItemComponent() {
  itemComponent_ = new ItemComponent();
  // TODO:セーブデータから所持品読み込み
}

UMyGameInstance *UMyGameInstance::GetInstance() {
  return UMyGameInstance::instance_;
}
