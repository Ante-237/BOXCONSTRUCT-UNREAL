
// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener.h"
#include "Chapter_UNREALGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;
	PointLight->SetVisibility(false);

	PointLight->SetLightColor(FLinearColor::Blue);

}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr) {
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

		AChapter_UNREALGameModeBase* MyGameMode = Cast<AChapter_UNREALGameModeBase>(GameMode);

		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
		}


	}
	
}

void ADelegateListener::EnableLight() {
	PointLight->SetVisibility(true);
}


void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr) {
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

		AChapter_UNREALGameModeBase* MyGameMode = Cast<AChapter_UNREALGameModeBase>(GameMode);

		if (MyGameMode != nullptr) {
			MyGameMode->MyStandardDelegate.Unbind();
		}
	}
}

