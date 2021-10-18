// Copyright Epic Games, Inc. All Rights Reserved.

#include "Arcade/Actors/ArcadeProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

AArcadeProjectile::AArcadeProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AArcadeProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AArcadeProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Add impulse, apply damage and destroy projectile if we hit a physics
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		return;
	}
	AController* MyOwnerInstigator = MyOwner->GetInstigatorController();
	
	// Returns a UClass* representing this class (UDamageType)
	UClass* DamageTypeClass = UDamageType::StaticClass();
	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor != MyOwner) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		// Generates HitEvent
		UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, MyOwnerInstigator, this, DamageTypeClass);
		// Destroy the projectile`
		Destroy();
	}
}