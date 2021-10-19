// Copyright Badsardines 2021.


#include "Arcade/GameModes/TestingGround.h"
#include "Arcade/HUD/ArcadeHUD.h"
#include "Arcade/Actors/DestructibleActor.h"
#include "kismet/GameplayStatics.h"

// Sets default value
ATestingGround::ATestingGround()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	HUDClass = AArcadeHUD::StaticClass();
}

void ATestingGround::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Destructible Actor Total: %d"), GetAllDestructibleActors());
}

int32 ATestingGround::GetAllDestructibleActors() const
{
	TArray<AActor*> DestructibleActors;
	UGameplayStatics::GetAllActorsOfClass(this, ADestructibleActor::StaticClass(), DestructibleActors);
	return DestructibleActors.Num();
}