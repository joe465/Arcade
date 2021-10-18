// Copyright Badsardines 2021.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class ARCADE_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingActor();

	void SetbCanRotate(bool value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RotateMeshComponent(float RotateSpeed);

	bool bCanRotate;

	// Called when sphere collider collides with something
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult);

	// Called when sphere collider is no longer collides with something
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereCollider;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation", meta = (AllowPrivateAccess = true))
	float RotateRate = 100.f;

	class AArcadeCharacter* PlayerPawn; 
};
