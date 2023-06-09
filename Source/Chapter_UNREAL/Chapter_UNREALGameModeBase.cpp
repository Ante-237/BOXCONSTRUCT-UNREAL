// Copyright Epic Games, Inc. All Rights Reserved.


#include "Chapter_UNREALGameModeBase.h"
#include "Blueprint/UserWidget.h"

void AChapter_UNREALGameModeBase::BeginPlay() {
	Super::BeginPlay();

	// Basic UE_LOG message
	UE_LOG(LogTemp, Warning, TEXT("Some warning message"));


	// UG_LOG message with arguments
	int intVar = 5;
	float floatVar = 3.0f;
	FString fstringVar = "an fstring variable";

	UE_LOG(LogTemp, Warning, TEXT("Text, %d, %f %s"), intVar, floatVar, *fstringVar);

	if (Widget) {
		UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), Widget);

		if (Menu) {
			Menu->AddToViewport();
			GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
		}
	}


}