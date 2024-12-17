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
  SetPlayerCharacter();
  SetItemComponent();
  SetDataBase();
}

void UMyGameInstance::Shutdown() {}

void UMyGameInstance::SetDataBase() {
  itemDataBase_ = NewObject<UItemDataBase>();
  itemDataBase_->BeginPlay(this);
  equipmentDataBase_ = NewObject<UEquipmentDataBase>();
  equipmentDataBase_->BeginPlay(this);
}
void UMyGameInstance::SetPlayerCharacter() {
  //WARNING::GetPlayerCharacter()はゲーム開始時にはnullptrを返す
  playerCharacter_ =
      Cast<AMaKCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
  if (!playerCharacter_) {
    UE_LOG(LogTemp, Warning, TEXT("playerCharacter_ is nullptr"));
  }
}
void UMyGameInstance::SetItemComponent() {
  itemComponent_ = new ItemComponent();
  // TODO:セーブデータから所持品読み込み
}

UMyGameInstance *UMyGameInstance::GetInstance() {
  return UMyGameInstance::instance_;
}
