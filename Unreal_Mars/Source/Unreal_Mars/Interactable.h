// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class UNREAL_MARS_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	/*
	* The Function that is called when the player interacts with the interactable
	* This function is marker as BlueprintImplementableEvent so that designers
	* May implement whatever custom functionality they want in blueprints
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void Interact(APlayerController* Controller);

	UPROPERTY(EditDefaultsOnly)
	FString Name;
	
	UPROPERTY(EditDefaultsOnly)
	FString Action;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	FString GetUseText() const { return FString::Printf(TEXT("%s : Press E to %s"), *Name, *Action); }
	
};
