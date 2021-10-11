// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPPrototype.generated.h"

UCLASS()
class ARCADE_API AFPPrototype : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPPrototype();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Handles moving forward/backward
	virtual void MoveForward(float Value);

	// Handles strafing movement
	virtual void MoveRight(float Value);

	// Handles camera left/right rotation for gamepad
	void TurnAtRate(float Value);

	// Handles camera up/down rotation for gamepad
	void LookUpAtRate(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Make the character jump
	virtual void Jump() override;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
		class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, Category = "Camera")
		float BaseRate = 100.f;
};
