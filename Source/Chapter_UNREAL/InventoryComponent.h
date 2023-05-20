// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryActor.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHAPTER_UNREAL_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY()
		TArray<AInventoryActor*> CurrentInventory;

	UFUNCTION()
		int32 AddToInventory(AInventoryActor* ActorToAdd);

	UFUNCTION()
		void RemoveFromInventory(AInventoryActor* ActorToRemove);


		
};
