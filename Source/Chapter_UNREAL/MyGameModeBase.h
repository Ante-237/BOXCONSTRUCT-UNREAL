// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstActor.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER_UNREAL_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UPROPERTY()
		AMyFirstActor* SpawnActor;

	UFUNCTION()
		void DestroyActorFunction();
};
