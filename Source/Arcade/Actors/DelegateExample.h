// Copyright Badsardines 2021.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateExample.generated.h"

// Will print a message when something overlapping this actor.
UCLASS()
class ARCADE_API ADelegateExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateExample();

	UFUNCTION()
	void OnSphereColliderBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USphereComponent* Root;


	float floatExp = 100.f;
};
