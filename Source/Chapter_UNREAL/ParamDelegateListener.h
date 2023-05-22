// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLIghtComponent.h"
#include "ParamDelegateListener.generated.h"

UCLASS()
class CHAPTER_UNREAL_API AParamDelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParamDelegateListener();

	UFUNCTION()
		void SetLightColor(FLinearColor LightColor, bool EnabledLight);

	UPROPERTY()
		UPointLightComponent* PointLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
