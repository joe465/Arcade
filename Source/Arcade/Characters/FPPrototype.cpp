// Fill out your copyright notice in the Description page of Project Settings.


#include "Arcade/Characters/FPPrototype.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"

// Sets default values
AFPPrototype::AFPPrototype()
{
 	// Set this character to call Tick() every frame. Turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AFPPrototype::BeginPlay()
{
	Super::BeginPlay();

	//...
}

// Called every frame
void AFPPrototype::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//...
}

// Establish the default input binding for this character
static void InitializeDefaultCharacterInputBindings()
{
	bool bBindingsAdded = false;
	
	if (bBindingsAdded == false)
	{
		bBindingsAdded = true;

		// Character Movement
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_MoveForward", EKeys::S, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_MoveForward", EKeys::Gamepad_RightY, 1.f));
		
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_MoveRight", EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_MoveRight", EKeys::Gamepad_RightX, 1.f));

		// Camera view
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_Turn", EKeys::MouseX, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_TurnAtRate", EKeys::Gamepad_RightX, 1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_LookUp", EKeys::MouseY, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("AFPPrototype_LookUpAtRate", EKeys::Gamepad_RightY, 1.f));
		
		// Jump
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("AFPPrototype_Jump", EKeys::SpaceBar));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("AFPPrototype_Jump", EKeys::Gamepad_FaceButton_Bottom));

		// Jog
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("AFPPrototype_Jog", EKeys::LeftShift));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("AFPPrototype_Jog", EKeys::Gamepad_LeftTrigger));
	}
}

// Called to bind functionality to input
void AFPPrototype::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InitializeDefaultCharacterInputBindings();
	
	PlayerInputComponent->BindAction("AFPPrototype_Jump", EInputEvent::IE_Pressed, this, &AFPPrototype::Jump);
	
	PlayerInputComponent->BindAxis("AFPPrototype_MoveForward", this, &AFPPrototype::MoveForward);
	PlayerInputComponent->BindAxis("AFPPrototype_MoveRight", this, &AFPPrototype::MoveRight);
	
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("AFPPrototype_LookUpAtRate", this, &AFPPrototype::LookUpAtRate);
	PlayerInputComponent->BindAxis("AFPPrototype_LookUp", this, &APawn::AddControllerPitchInput);
	
	PlayerInputComponent->BindAxis("AFPPrototype_TurnAtRate", this, &AFPPrototype::TurnAtRate);
	PlayerInputComponent->BindAxis("AFPPrototype_Turn", this, &APawn::AddControllerYawInput);
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

void AFPPrototype::TurnAtRate(float Value)
{
	if (Value != 0.f)
	{
		AddControllerYawInput(Value * BaseRate * GetWorld()->GetDeltaSeconds());
	}
}

void AFPPrototype::LookUpAtRate(float Value)
{
	if (Value != 0.f)
	{
		AddControllerPitchInput(Value * BaseRate * GetWorld()->GetDeltaSeconds());
	}
}

// Make the character jump
void AFPPrototype::Jump()
{
	Super::Jump();

	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}