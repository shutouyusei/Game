#pragma once
struct FStatsStruct;
enum class StatsType;
class StatsBase;

class PlayerStatsComponent {
public:
  void ComponentSetUp();
  void ComponentSetUp(FStatsStruct stats);
  void ComponentCleanUp();
  StatsBase *GetStats() { return stats_; }
private:
  static StatsBase *stats_;
};
