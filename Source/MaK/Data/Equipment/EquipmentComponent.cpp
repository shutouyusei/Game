#include "EquipmentComponent.h"
#include "../../Character/MaKCharacter.h"
#include "../../GameInstance/MyGameInstance.h"
#include "EquipmentDataBase.h"

UEquipmentComponent::UEquipmentComponent() {}

UEquipmentDataBase *UEquipmentComponent::GetEquipmentDataBase() {
  return UMyGameInstance::GetInstance()->GetEquipmentDataBase();
}
void UEquipmentComponent::AddEquipment(const int id, const int num) {
  for (FHave &equipment : haveEquipments) {
    if (equipment.id == id) {
      equipment.num += num;
      return;
    }
  }
  haveEquipments.Add(FHave(id, num));
}

void UEquipmentComponent::RemoveEquipment(const int id, const int num) {
  int index = 0;
  for (FHave &equipment : haveEquipments) {
    if (equipment.id == id) {
      equipment.num -= num;
      if (equipment.num <= 0) {
        haveEquipments.RemoveAt(index);
      }
      return;
    }
    index++;
  }
}
