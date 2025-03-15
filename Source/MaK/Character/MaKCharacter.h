// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "MaKCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config = Game)
class AMaKCharacter : public ACharacter {
  GENERATED_BODY()
public:
  FVector2D GetMoveInputValue();
  FVector2D GetCameraForwardVector();

protected:
  UPROPERTY()
  UEnhancedInputComponent *EnhancedInputComponent;

private:
  /** Camera boom positioning the camera behind the character */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  USpringArmComponent *CameraBoom;

  /** Follow camera */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  UCameraComponent *FollowCamera;

  /** MappingContext */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputMappingContext *DefaultMappingContext;

  /** Jump Input Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *JumpAction;

  /** Move Input Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *MoveAction;

  /** Look Input Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input,
            meta = (AllowPrivateAccess = "true"))
  UInputAction *LookAction;

public:
  AMaKCharacter();
  ~AMaKCharacter();
  void SetCanJump(bool enable);

protected:
  virtual void BeginPlay() override;
  /** Called for movement input */
  void Move(const FInputActionValue &Value);
  void MyJump();

  /** Called for looking input */
  void Look(const FInputActionValue &Value);

protected:
  virtual void NotifyControllerChanged() override;

  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;

public:
  /** Returns CameraBoom subobject **/
  FORCEINLINE class USpringArmComponent *GetCameraBoom() const {
    return CameraBoom;
  }
  /** Returns FollowCamera subobject **/
  FORCEINLINE class UCameraComponent *GetFollowCamera() const {
    return FollowCamera;
  }

private:
  UPROPERTY()
  bool can_jump_ = true;
};
