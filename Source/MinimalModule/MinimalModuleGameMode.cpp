// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MinimalModuleGameMode.h"
#include "MinimalModuleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMinimalModuleGameMode::AMinimalModuleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
