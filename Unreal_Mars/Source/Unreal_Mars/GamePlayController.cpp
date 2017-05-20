// Fill out your copyright notice in the Description page of Project Settings.

#include "GamePlayController.h"
#include "Interactable.h"
#include "Unreal_Mars.h"

void AGamePlayController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &AGamePlayController::Interact);
}

void AGamePlayController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}

}




