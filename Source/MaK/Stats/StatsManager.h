#pragma once

class StatsBase;
class AActor;

class StatsManager {
public:
  StatsManager();
  ~StatsManager();

  void AddStats(AActor *actor, StatsBase *stats);
  void RemoveStats(AActor *actor);
  StatsBase *GetStats(AActor *actor);

private:
  // a combination of actor and stats
  TMap<AActor *, StatsBase *> statsMap_;
};
