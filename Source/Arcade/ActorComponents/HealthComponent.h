// Copyright Badsardines 2021.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

// Handles Actor's health
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UFUNCTION()
	void OnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Health")
		float MaxHealth = 100.f;

	// Current actor's health
	float Health;
};
