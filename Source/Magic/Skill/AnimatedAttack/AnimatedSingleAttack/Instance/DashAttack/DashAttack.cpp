#include "DashAttack.h"

UDashAttack::~UDashAttack() {
}

void UDashAttack::Activate() {
  // スキルの実行
  attack_module_->Attack();
  // スキルの終了
  EndPlay();
}

void UDashAttack::OnAttack(ACharacter *target) {
  // 攻撃対象を指定
  UE_LOG(LogTemp, Warning, TEXT("DashAttack: %s"), *target->GetName());
}
