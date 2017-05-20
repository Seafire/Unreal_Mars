// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUp.h"
#include "Unreal_Mars.h"

APickUp::APickUp()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");

	ItemID = FName("Please enter an ID");
}



