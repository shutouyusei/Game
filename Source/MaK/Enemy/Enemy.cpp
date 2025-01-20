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
  StatsComponent().GetStatsManager()->RemoveStats(this);

  StatsBase *statsBase = StatsComponent().GetStatsManager()->GetStats(this);
  StatsFactory().DestroyStats(statsBase);
}
void AEnemy::SetStats(FStatsStruct stats) {
  // Set stats
  //
  StatsComponent statsComponent;
  StatsBase *statsBase = StatsFactory().CreateStats(stats);
  statsComponent.GetStatsManager()->AddStats(this, statsBase);
}
