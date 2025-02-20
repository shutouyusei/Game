#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "CoreMinimal.h"

#include "BTT_EnemyMove.generated.h"

// NOTE:敵の動きを制御するクラス
// AIPerceptionと関連する
UCLASS()
class UBTT_EnemyMove : public UBTTaskNode {
  GENERATED_BODY()
public:
  UBTT_EnemyMove();

  virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp,
                                          uint8 *NodeMemory) override;
  virtual void TickTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory,
                        float DeltaSeconds) override;
};
