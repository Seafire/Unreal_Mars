// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Unreal_MarsGameMode.h"
#include "Unreal_MarsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnreal_MarsGameMode::AUnreal_MarsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
