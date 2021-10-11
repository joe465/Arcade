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

	virtual void MoveForward(float Value);

	virtual void MoveRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Jump() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
		class UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
		class USpringArmComponent* CameraBoom;
};
