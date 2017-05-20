// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GamplayGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_MARS_API AGamplayGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	class UDataTable* GetItemDB() const { return ItemID; }

protected:

	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ItemID;
	
};
