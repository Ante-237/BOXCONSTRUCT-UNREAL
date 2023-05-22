
// Fill out your copyright notice in the Description page of Project Settings.


#include "ParamDelegateListener.h"
#include "Chapter_UNREALGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	RootComponent = PointLight;

}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	Super::BeginPlay();

	UWorld* TheWorld = GetWorld();

	if (TheWorld != nullptr) {

		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

		AChapter_UNREALGameModeBase* MyGameMode = Cast<AChapter_UNREALGameModeBase>(GameMode);

		if (MyGameMode != nullptr) {
			MyGameMode->MyParamaterDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor, false);
		}
	}
	
}

// Called every frame
void AParamDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParamDelegateListener::SetLightColor(FLinearColor LightColor, bool EnabledLight) {
	PointLight->SetLightColor(LightColor);
	PointLight->SetVisibility(EnabledLight);
}

