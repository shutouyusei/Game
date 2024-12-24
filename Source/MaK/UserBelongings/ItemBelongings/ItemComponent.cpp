#include "ItemComponent.h"

// initialize static member
UserBelongings *ItemComponent::fItemBelongings_ = nullptr;
UserBelongings *ItemComponent::fAbilityBookBelongings_ = nullptr;
UserBelongings *ItemComponent::fImportantBelongings_ = nullptr;
UserBelongings *ItemComponent::materialBelongings_ = nullptr;
void ItemComponent::ComponentSetUp() {
  // initialize UserBelongings
}

UserBelongings *ItemComponent::GetItemBelongings(ItemType type) {
  switch (type) {
  case ItemType::FItem:
    return fItemBelongings_;
  case ItemType::FAbilityBook:
    return fAbilityBookBelongings_;
  case ItemType::FImportant:
    return fImportantBelongings_;
  case ItemType::Material:
    return materialBelongings_;
  default:
    UE_LOG(LogTemp, Warning, TEXT("Invalid ItemType"));
    return nullptr;
  }
}
