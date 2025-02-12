#include "Enemy.h"
#include "AbilityManager.h"
#include "Attack/AttackCollision.h"
#include "Components/ChildActorComponent.h"
#include "EnemyContoroller.h"
#include "Perception/AIPerceptionComponent.h"
#include "StatusComponent.h"

AEnemy::AEnemy() {
  // Constructor
  Tags.Add("Game");
  // AI Perception
  PerceptionComponent =
      CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComponent");
  AddOwnedComponent(PerceptionComponent);

  // Ability Manager
  abilityManager_ = CreateDefaultSubobject<UAbilityManager>("AbilityManager");
  // Status Component
  StatusComponent = CreateDefaultSubobject<UStatusComponent>("StatusComponent");
}

AEnemy::~AEnemy() {}

void AEnemy::BeginPlay() {
  // Called when the game starts or when spawned
  Super::BeginPlay();
}
