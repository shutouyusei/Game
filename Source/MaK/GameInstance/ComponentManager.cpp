#include "ComponentManager.h"
#include "ItemDataBaseComponent.h"
#include "StatsComponent.h"

void ComponentManager::SetUpComponents() {
  StatsComponent statsComponent;
  statsComponent.ComponentSetUp();
}

void ComponentManager::CleanUpComponents() {
  // Clean up
  StatsComponent statsComponent;
  statsComponent.ComponentCleanUp();
}
