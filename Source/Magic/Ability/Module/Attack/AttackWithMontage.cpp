#include "AttackWithMontage.h"
#include "GameFramework/Character.h"
#include "Module/Attack/Attack.h"
#include "Module/Montage/MontagePlayer.h"
// TODO:MontagePlayerいらなくね

void UAttackWithMontage::AttackWithMontage(FOnMontageEnded delegate, AAttackCollision *attack_collision, AActor *applyier) {
  ACharacter *character = Cast<ACharacter>(applyier);
  MontagePlayer::PlayMontage(character->GetMesh()->GetAnimInstance(), montage_, delegate);
  AttackPlayer::Attack(attack_collision, applyier, damage_);
}

void UAttackWithMontage::EndAttack(AAttackCollision *attack_collision) {
  AttackPlayer::EndAttack(attack_collision);
}

void UAttackWithMontage::OnMontageEnded(UAnimMontage *montage, bool interrupted) {
}
