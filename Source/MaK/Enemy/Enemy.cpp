#include "Enemy.h"
#include "AbilityManager.h"
#include "Attack/AttackCollision.h"
#include "Components/ChildActorComponent.h"
#include "EnemyContoroller.h"
#include "Perception/AIPerceptionComponent.h"
#include "StatsComponent.h"
#include "StatsFactory.h"

AEnemy::AEnemy() {
  // Constructor
  Tags.Add("Game");
  // AI Perception
  PerceptionComponent =
      CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComponent");
  AddOwnedComponent(PerceptionComponent);

  // Ability Manager
  abilityManager_ = CreateDefaultSubobject<UAbilityManager>("AbilityManager");

  // Attack Collision
  weapon_ = CreateDefaultSubobject<UChildActorComponent>("Weapon");
  weapon_->SetupAttachment(GetMesh());
  weapon_->SetChildActorClass(AAttackCollision::StaticClass());
}

AEnemy::~AEnemy() {
  // Destructor
  StatsComponent statsComponent;
  // delete Stats Base
  StatsBase *statsBase = StatsComponent().GetStatsManager()->GetStats(this);
  delete statsBase;
  statsBase = nullptr;
  // remove notification for manager
  StatsComponent().GetStatsManager()->RemoveStats(this);
}

void AEnemy::BeginPlay() {
  // Called when the game starts or when spawned
  Super::BeginPlay();
  // Set stats
  StatsComponent statsComponent;
  StatsBase *statsBase = StatsFactory().CreateStats(stats_);
  statsComponent.GetStatsManager()->AddStats(this, statsBase);
  statsBase->HP_.SetDeathCallback([this]() {
    UE_LOG(LogTemp, Warning, TEXT("Enemy %s died"), *GetName());
    Destroy();
  });
}
