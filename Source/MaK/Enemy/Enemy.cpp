#include "Enemy.h"
#include "AbilityManager.h"
#include "Attack/AttackCollision.h"
#include "Components/ChildActorComponent.h"
#include "EnemyContoroller.h"
#include "Perception/AIPerceptionComponent.h"
#include "StatsComponent.h"

AEnemy::AEnemy() {
  // Constructor
  Tags.Add("Game");
  // AI Perception
  PerceptionComponent =
      CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComponent");
  AddOwnedComponent(PerceptionComponent);

  // Ability Manager
  abilityManager_ = CreateDefaultSubobject<UAbilityManager>("AbilityManager");
  // Stats Component
  StatsComponent = CreateDefaultSubobject<UStatsComponent>("StatsComponent");
}

AEnemy::~AEnemy() {}

void AEnemy::BeginPlay() {
  // Called when the game starts or when spawned
  Super::BeginPlay();
}
