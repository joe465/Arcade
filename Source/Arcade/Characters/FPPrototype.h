// Copyright Badsardines 2021.

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

	void Jog();
	
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

	UPROPERTY(EditDefaultsOnly, Category = "CameraShake")
		TSubclassOf<class UHeadBob> HeadBob;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		float BaseTurnRate;

	UPROPERTY(EditDefaultsOnly, Category = "CameraShake")
		float HeadBobScale = 0.65f;

	class AFPPrototypeController* CharacterController;
	
	void SetCharcterMovementSpeed(float Value);

	void ResetValue();
	
	// TODO: Implement "Head bob"
};
