// Copyright Badsardines 2021.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TestingGroundActorTeleporter.generated.h"

/**
 * 
 */
UCLASS()
class ARCADE_API ATestingGroundActorTeleporter : public ATriggerBox
{
	GENERATED_BODY()

public:
	// Constructor for teleporter
	ATestingGroundActorTeleporter();

protected:
	// Hide collision component and sprite component in-game
	virtual void PostInitializeComponents() override;

	// setup a notification at Begin-Overlap
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
