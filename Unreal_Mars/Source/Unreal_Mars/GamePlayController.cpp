// Fill out your copyright notice in the Description page of Project Settings.

#include "GamePlayController.h"
#include "Interactable.h"
#include "GamplayGameMode.h"
#include "Unreal_MarsCharacter.h"
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

void AGamePlayController::AddItemToInventoryByID(FName ID)
{
	AGamplayGameMode* GameMode = Cast<AGamplayGameMode>(GetWorld()->GetAuthGameMode());
	UDataTable* ItemTable = GameMode->GetItemDB();

	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		Inventory.Add(*ItemToAdd);
	}
}

void AGamePlayController::CraftItem(FInventoryItem ItemA, FInventoryItem ItemB, AGamePlayController* Controller)
{
	// Check we've made a valid craft
	for (auto Craft : ItemB.CraftCombitations)
	{
		if (Craft.ComponentID == ItemA.ItemID)
		{
			if (Craft.bDestroyItemA)
			{
				Inventory.RemoveSingle(ItemA);
				
			}

			if (Craft.DestroyItemB)
			{
				Inventory.RemoveSingle(ItemB);
			}

			AddItemToInventoryByID(Craft.ProductID);

			ReloadInventory();
		}
	}
}




