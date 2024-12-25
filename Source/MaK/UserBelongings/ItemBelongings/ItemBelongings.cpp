#include "ItemBelongings.h"
#include "CoreMinimal.h"

ItemBelongings::ItemBelongings(TArray<BelongingAmount> &belongings)
    : UserBelongings(belongings) {}

ItemBelongings::~ItemBelongings() {}
