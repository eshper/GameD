// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameDGameMode.h"
#include "GameDCharacter.h"

AGameDGameMode::AGameDGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AGameDCharacter::StaticClass();	
}
