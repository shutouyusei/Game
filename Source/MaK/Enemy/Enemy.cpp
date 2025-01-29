#include "Enemy.h"
#include "StatsComponent.h"
#include "StatsFactory.h"

AEnemy::AEnemy() {
  // Constructor
  Tags.Add("Game");
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
