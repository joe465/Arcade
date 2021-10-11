// Fill out your copyright notice in the Description page of Project Settings.


#include "Arcade/Characters/FPPrototype.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"

// Sets default values
AFPPrototype::AFPPrototype()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 6.5f;
	CameraBoom->SetRelativeLocation(FVector(10.5f, 1.7f, 64.f), false);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void AFPPrototype::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPPrototype::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Establish the default input binding for this character
static void InitializeDefaultPawnInputBindings()
{
	bool bBindingsAdded = false;
	
	if (bBindingsAdded == false)
	{
		bBindingsAdded = true;

		// Character Movement
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("MoveForward", EKeys::S, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("MoveForward", EKeys::Gamepad_RightY, 1.f));
		
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("MoveRight", EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("MoveRight", EKeys::Gamepad_RightX, 1.f));

		// Camera view
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("TurnRate", EKeys::MouseX, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("TurnRate", EKeys::Gamepad_RightX, 1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("LookUp", EKeys::MouseY, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("LookUpRate", EKeys::Gamepad_RightY, 1.f));
		
		// Jump
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Jump", EKeys::SpaceBar));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Jump", EKeys::Gamepad_FaceButton_Bottom));

		// Jog
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Jog", EKeys::LeftShift));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Jog", EKeys::Gamepad_LeftTrigger));
	}
}

// Called to bind functionality to input
void AFPPrototype::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InitializeDefaultPawnInputBindings();

	
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AFPPrototype::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPPrototype::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPPrototype::MoveRight);
}

// Character Move Forward
void AFPPrototype::MoveForward(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

// Character Strafe
void AFPPrototype::MoveRight(float Value)
{
	if (Value != 0.f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}


// Character jump
void AFPPrototype::Jump()
{
	Super::Jump();

	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}