// Copyright Badsardines 2021.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleActor.generated.h"

UCLASS()
class ARCADE_API ADestructibleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleActor();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
		UStaticMeshComponent* Mesh;
	
	UPROPERTY(VisibleAnywhere, Category = "Health")
		class UHealthComponent* HealthComp;
};
