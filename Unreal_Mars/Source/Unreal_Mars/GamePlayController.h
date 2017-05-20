// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayController.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_MARS_API AGamePlayController : public APlayerController
{
	GENERATED_BODY()
	
public:

	// The Interactable the player is currently looing at. This will be nullptr if the player is not looking at something that is interactable
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class AInteractable* CurrentInteractable;
	
	void Interact();

protected:

	virtual void SetupInputComponent() override;
	
};
