// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcadeGameMode.h"
#include "Arcade/HUD/ArcadeHUD.h"
#include "Arcade/Characters/ArcadeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArcadeGameMode::AArcadeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AArcadeHUD::StaticClass();
}
