// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaKCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputActionValue.h"
#include "Math/Vector2D.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AMaKCharacter
AMaKCharacter::AMaKCharacter() {
  // Set size for collision capsule
  GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

  // Don't rotate when the controller rotates. Let that just affect the camera.
  bUseControllerRotationPitch = false;
  bUseControllerRotationYaw = false;
  bUseControllerRotationRoll = false;

  // Configure character movement
  GetCharacterMovement()->bOrientRotationToMovement = true;            // Character moves in the direction of input...
  GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

  // Note: For faster iteration times these variables, and many more, can be
  // tweaked in the Character Blueprint instead of recompiling to adjust them
  GetCharacterMovement()->JumpZVelocity = 700.f;
  GetCharacterMovement()->AirControl = 0.35f;
  GetCharacterMovement()->MaxWalkSpeed = 500.f;
  GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
  GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
  GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
  // Create a camera boom (pulls in towards the player if there is a collision)
  CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
  CameraBoom->SetupAttachment(RootComponent);
  CameraBoom->TargetArmLength = 400.0f;       // The camera follows at this distance behind the character
  CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

  // Create a follow camera
  FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
  FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the
  FollowCamera->bUsePawnControlRotation = false;                              // Camera does not rotate relative to arm

  // Note: The skeletal mesh and anim blueprint references on the Mesh component
  // (inherited from Character) are set in the derived blueprint asset named
  // ThirdPersonCharacter (to avoid direct content references in C++)
}

AMaKCharacter::~AMaKCharacter() {}

//////////////////////////////////////////////////////////////////////////
// Input

void AMaKCharacter::NotifyControllerChanged() {
  Super::NotifyControllerChanged();

  // Add Input Mapping Context
  if (APlayerController *PlayerController =
          Cast<APlayerController>(Controller)) {
    if (UEnhancedInputLocalPlayerSubsystem *Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
                PlayerController->GetLocalPlayer())) {
      Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
  }
}

void AMaKCharacter::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  // Set up action bindings
  EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
  if (EnhancedInputComponent != nullptr) {

    // Jumping
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this,
                                       &AMaKCharacter::MyJump);
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed,
                                       this, &ACharacter::StopJumping);

    // Moving
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered,
                                       this, &AMaKCharacter::Move);

    // Looking
    EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered,
                                       this, &AMaKCharacter::Look);
  } else {
    UE_LOG(
        LogTemplateCharacter, Error,
        TEXT("'%s' Failed to find an Enhanced Input component! This template "
             "is built to use the Enhanced Input system. If you intend to use "
             "the legacy system, then you will need to update this C++ file."),
        *GetNameSafe(this));
  }
}
void AMaKCharacter::BeginPlay() { Super::BeginPlay(); }

void AMaKCharacter::Move(const FInputActionValue &Value) {
  // input is a Vector2D
  FVector2D MovementVector = Value.Get<FVector2D>();

  if (Controller != nullptr) {
    // find out which way is forward
    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    // get forward vector
    const FVector ForwardDirection =
        FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

    // get right vector
    const FVector RightDirection =
        FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    // add movement
    AddMovementInput(ForwardDirection, MovementVector.Y);
    AddMovementInput(RightDirection, MovementVector.X);
  }
}

void AMaKCharacter::SetCanJump(bool enable) {
  can_jump_ = enable;
}
void AMaKCharacter::MyJump() {
  if (can_jump_) {
    ACharacter::Jump();
  }
}

void AMaKCharacter::Look(const FInputActionValue &Value) {
  // input is a Vector2D
  FVector2D LookAxisVector = Value.Get<FVector2D>();

  if (Controller != nullptr) {
    // add yaw and pitch input to controller
    AddControllerYawInput(LookAxisVector.X);
    AddControllerPitchInput(LookAxisVector.Y);
  }
}

FVector2D AMaKCharacter::GetMoveInputValue() {
  FEnhancedInputActionValueBinding *MoveBinding = &EnhancedInputComponent->BindActionValue(MoveAction);
  const FVector2D MoveInputValue = MoveBinding->GetValue().Get<FVector2D>();
  return MoveInputValue;
}

FVector2D AMaKCharacter::GetCameraForwardVector() {
  FVector2D CameraForwardVector = FVector2D::ZeroVector;
  if (Controller != nullptr) {
    // Get Camera Forward Vector
    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);
    const FVector ForwardDirection =
        FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    CameraForwardVector = FVector2D(ForwardDirection.X, ForwardDirection.Y);
  }
  return CameraForwardVector;
}
