// Copyright Badsardines 2021.


#include "Arcade/Triggers/TestingGroundActorTeleporter.h"
#include "Components/BillboardComponent.h"
#include "Components/ShapeComponent.h"
#include "Arcade/Actors/DestructibleActor.h"

ATestingGroundActorTeleporter::ATestingGroundActorTeleporter()
{
	SetActorHiddenInGame(false);
}

void ATestingGroundActorTeleporter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GetCollisionComponent()->SetHiddenInGame(true);

#if WITH_EDITORONLY_DATA
	GetSpriteComponent()->SetHiddenInGame(true);
#endif
}

void ATestingGroundActorTeleporter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ADestructibleActor* DestructibleActors = Cast<ADestructibleActor>(OtherActor);
	if (DestructibleActors != nullptr)
	{
		DestructibleActors->TeleportToDefault();
	}
}
