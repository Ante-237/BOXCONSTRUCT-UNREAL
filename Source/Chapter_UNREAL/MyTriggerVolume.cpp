// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume.h"
#include "Chapter_UNREALGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	TriggerZone->SetBoxExtent(FVector(200, 200, 100));
}

void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName()));

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);


	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr) {
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

		AChapter_UNREALGameModeBase* MyGameMode = Cast<AChapter_UNREALGameModeBase>(GameMode);

		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.ExecuteIfBound();

			auto Color = FLinearColor(1, 0, 0, 1);
			MyGameMode->MyParamaterDelegate.ExecuteIfBound(Color);

			MyGameMode->MyMulticastDelegate.Broadcast();

			onPlayerEntered.Broadcast();
		}


	}
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor) {
	auto Message = FString::Printf(TEXT("%s left me"), *(OtherActor->GetName()));
	GEngine->AddOnScreenDebugMessage(01, 1, FColor::Red, Message);
}

