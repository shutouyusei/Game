#include "ItemComponent.h"
#include "../ItemBelongings/ItemBelongingsFactory.h"
#include "CoreMinimal.h"

// initialize static member
UserBelongings *ItemComponent::fItemBelongings_ = nullptr;
UserBelongings *ItemComponent::fAbilityBookBelongings_ = nullptr;
UserBelongings *ItemComponent::fImportantBelongings_ = nullptr;
UserBelongings *ItemComponent::fmaterialBelongings_ = nullptr;

ItemComponent::ItemComponent() {}

ItemComponent::~ItemComponent() {}

void ItemComponent::ComponentSetUp() {
  if (fItemBelongings_ != nullptr) {
    return;
  }
  // initialize UserBelongings
  fItemBelongings_ = FItemBelongingsFactory().CreateBelongings();
  fAbilityBookBelongings_ = FAbilityBookBelongingsFactory().CreateBelongings();
  fImportantBelongings_ = FImportantBelongingsFactory().CreateBelongings();
  fmaterialBelongings_ = MaterialBelongingsFactory().CreateBelongings();
}

void ItemComponent::ComponentCleanUp() {
  delete fItemBelongings_;
  fItemBelongings_ = nullptr;
  delete fAbilityBookBelongings_;
  fAbilityBookBelongings_ = nullptr;
  delete fImportantBelongings_;
  fImportantBelongings_ = nullptr;
  delete fmaterialBelongings_;
  fmaterialBelongings_ = nullptr;
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
    return fmaterialBelongings_;
  default:
    UE_LOG(LogTemp, Warning, TEXT("Invalid ItemType"));
    return nullptr;
  }
}
