#include "ItemBelongings.h"
#include "CoreMinimal.h"

ItemBelongings::ItemBelongings(TArray<BelongingAmount> &belongings)
    : UserBelongings(belongings) {}

ItemBelongings::~ItemBelongings() {}

void ItemBelongings::Use(int id) {}

void ItemBelongings::Use(const char *name) {}
