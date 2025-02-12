#include "StatusComponent.h"

UStatusComponent::UStatusComponent() {
  HP_ = CreateDefaultSubobject<UStatusParameter>("HP");
  MP_ = CreateDefaultSubobject<UStatusParameter>("MP");
  AD_ = CreateDefaultSubobject<UStatusParameter>("AD");
  AP_ = CreateDefaultSubobject<UStatusParameter>("AP");
  AR_ = CreateDefaultSubobject<UStatusParameter>("AR");
  MR_ = CreateDefaultSubobject<UStatusParameter>("MR");
}

UStatusComponent::~UStatusComponent() {}

float UStatusComponent::GetHP() {
  if (currentHP_ > HP_->Get()) {
    currentHP_ = HP_->Get();
  }
  return currentHP_;
}

void UStatusComponent::Damage(float damage) {
  currentHP_ -= damage;
  if (currentHP_ < 0) {
    currentHP_ = 0;
  }
}

void UStatusComponent::Heal(float heal) {
  currentHP_ += heal;
  if (currentHP_ > HP_->Get()) {
    currentHP_ = HP_->Get();
  }
}

float UStatusComponent::GetMP() {
  if (currentMP_ > MP_->Get()) {
    currentMP_ = MP_->Get();
  }
  return currentMP_;
}

bool UStatusComponent::UseMP(float mp) {
  if (mp <= currentMP_) {
    currentMP_ -= mp;
    return true;
  } else {
    return false;
  }
}
void UStatusComponent::RestoreMP(float mp) {
  currentMP_ += mp;
  if (currentMP_ > MP_->Get()) {
    currentMP_ = MP_->Get();
  }
}
