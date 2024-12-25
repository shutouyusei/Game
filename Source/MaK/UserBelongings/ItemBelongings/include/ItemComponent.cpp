#include "ItemComponent.h"
#include "../ItemBelongingsFactory.h"
#include "CoreMinimal.h"

// initialize static member
UserBelongings *ItemComponent::fItemBelongings_ = nullptr;
UserBelongings *ItemComponent::fAbilityBookBelongings_ = nullptr;
UserBelongings *ItemComponent::fImportantBelongings_ = nullptr;
UserBelongings *ItemComponent::fmaterialBelongings_ = nullptr;

ItemComponent::ItemComponent() {}

ItemComponent::~ItemComponent() {}

void ItemComponent::ComponentSetUp() {
  // initialize UserBelongings
  fItemBelongings_ = FItemBelongingsFactory().CreateBelongings();
  fAbilityBookBelongings_ = FAbilityBookBelongingsFactory().CreateBelongings();
  fImportantBelongings_ = FImportantBelongingsFactory().CreateBelongings();
  fmaterialBelongings_ = MaterialBelongingsFactory().CreateBelongings();
}

void ItemComponent::ComponentCleanUp() {
  delete fItemBelongings_;
  delete fAbilityBookBelongings_;
  delete fImportantBelongings_;
  delete fmaterialBelongings_;
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
