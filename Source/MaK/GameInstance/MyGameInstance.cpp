#include "MyGameInstance.h"
#include "ComponentManager.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// init static variable
UMyGameInstance *UMyGameInstance::instance_ = nullptr;

void UMyGameInstance::Init() {
  UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance"));
  instance_ = this;
  ComponentManager::SetUpComponents();
}

void UMyGameInstance::Shutdown() { ComponentManager::CleanUpComponents(); }
