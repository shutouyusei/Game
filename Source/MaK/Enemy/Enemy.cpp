#include "Enemy.h"
#include "EnemyContoroller.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemy::AEnemy() {
  // Constructor
  Tags.Add("Game");
  // AI Perception
  PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComponent");
  //視界
  SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("SightConfig");
  if(SightConfig != nullptr){
    PerceptionComponent->ConfigureSense(*SightConfig);
  }
  // Set delegate for perception
  PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(
      this, &AEnemy::OnPerceptionUpdated);

  AddOwnedComponent(PerceptionComponent);
  // Ability Manager
  abilityManager_ = CreateDefaultSubobject<UAbilityManager>("AbilityManager");
  // Status Component
  StatusComponent = CreateDefaultSubobject<UStatusComponent>("StatusComponent");
}

AEnemy::~AEnemy() {}

void AEnemy::BeginPlay() {
  // Called when the game starts or when spawned
  Super::BeginPlay();
}

void AEnemy::OnPerceptionUpdated(AActor *actor, FAIStimulus stimulus) {
  // Called when perception is updated
  AEnemyContoroller *controller = Cast<AEnemyContoroller>(GetController());
  for (auto actor : actors) {
    if (actor->ActorHasTag("ally")) {
      UE_LOG(LogTemp, Warning, TEXT("Ally Detected"));
      controller->actors_.AddUnique(actor);
    }
  }
}
