#include "Enemy.h"
#include "StatsComponent.h"
#include "StatsFactory.h"

AEnemy::AEnemy() {
  // Constructor
}

AEnemy::~AEnemy() {
  // Destructor
  StatsComponent statsComponent;
  StatsBase *statsBase = statsComponent.GetStatsManager()->GetStats(this);
  delete statsBase;
  StatsComponent().GetStatsManager()->RemoveStats(this);
}
void AEnemy::SetStats(FStatsStruct stats) {
  // Set stats
  //
  StatsComponent statsComponent;
  StatsBase *statsBase = StatsFactory().CreateStats(stats);
  statsComponent.GetStatsManager()->AddStats(this, statsBase);
}
