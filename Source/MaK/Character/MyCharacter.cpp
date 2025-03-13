#include "MyCharacter.h"

AMyCharacter::AMyCharacter() {
  // 味方ポーンのタグはally
  this->Tags.Add("ally");
}

AMyCharacter::~AMyCharacter() {}

void AMyCharacter::BeginPlay() {
  Super::BeginPlay();
}


void AMyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason) {
  Super::EndPlay(EndPlayReason);
}

