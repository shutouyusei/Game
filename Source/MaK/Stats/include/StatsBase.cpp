#include "StatsBase.h"

UStatsBase::UStatsBase() {}

UStatsBase::~UStatsBase() {}

float UStatsBase::GetHP() {
  if (currentHP_ > HP_->Get()) {
    currentHP_ = HP_->Get();
  }
  return currentHP_;
}

void UStatsBase::Damage(float damage) {
  currentHP_ -= damage;
  if (currentHP_ < 0) {
    currentHP_ = 0;
  }
}

void UStatsBase::Heal(float heal) {
  currentHP_ += heal;
  if (currentHP_ > HP_->Get()) {
    currentHP_ = HP_->Get();
  }
}

float UStatsBase::GetMP() {
  if (currentMP_ > MP_->Get()) {
    currentMP_ = MP_->Get();
  }
  return currentMP_;
}

bool UStatsBase::UseMP(float mp) {
  if (mp <= currentMP_) {
    currentMP_ -= mp;
    return true;
  } else {
    return false;
  }
}
void UStatsBase::RestoreMP(float mp) {
  currentMP_ += mp;
  if (currentMP_ > MP_->Get()) {
    currentMP_ = MP_->Get();
  }
}
