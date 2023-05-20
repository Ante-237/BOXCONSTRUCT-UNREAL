



// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyFirstActor.h"



void AMyGameModeBase::BeginPlay() {
	Super::BeginPlay();

	// Display red message on screen for 10 seconds
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Spawning"));

	// spawn an instance of the AMyFirstActor class at the default location.
	FTransform SpawnLocation;
	SpawnActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnLocation);

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AMyGameModeBase::DestroyActorFunction, 10);
}

void AMyGameModeBase::DestroyActorFunction() {
	if (SpawnActor != nullptr) {
		// Display a red message on the screen for 10 seconds
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Destroyed"));
		SpawnActor->Destroy();
	}
}

