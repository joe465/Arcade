// Copyright Badsardines 2021.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestingGround.generated.h"

/**
 * 
 */
UCLASS()
class ARCADE_API ATestingGround : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestingGround();
	
	int32 GetAllDestructibleActors() const;

protected:
	void BeginPlay() override;
};
