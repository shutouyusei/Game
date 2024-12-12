#include "StatsHandler.h"

StatsHandler::StatsHandler() : CurrentHP(0), CurrentMP(0) {}
void StatsHandler::SetUpStats(/* some save data */) {}

void StatsHandler::ChangeMaxStats(const FCharacterStats &stats) {
  MaxStats = stats;
  if (CurrentHP > MaxStats.HP)
    CurrentHP = MaxStats.HP;
  if (CurrentMP > MaxStats.MP)
    CurrentMP = MaxStats.MP;
}

void StatsHandler::ChangeCurrentHP(const float varHP) {
  if (CurrentHP + varHP >= MaxStats.HP) {
    CurrentHP = MaxStats.HP;
  } else {
    CurrentHP += varHP;
  }
}

void StatsHandler::ChangeCurrentMP(const float varMP) {
  if (CurrentMP + varMP >= MaxStats.MP) {
    CurrentMP = MaxStats.MP;
  } else {
    CurrentMP += varMP;
  }
}
