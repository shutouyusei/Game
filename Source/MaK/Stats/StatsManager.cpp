#include "StatsManager.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StatsBase.h"

StatsManager::StatsManager() {}
StatsManager::~StatsManager() {}

void StatsManager::AddStats(AActor *actor, StatsBase *stats) {
  statsMap_.Add(actor, stats);
}

void StatsManager::RemoveStats(AActor *actor) { statsMap_.Remove(actor); }

StatsBase *StatsManager::GetStats(AActor *actor) {
  return statsMap_.FindRef(actor);
}
