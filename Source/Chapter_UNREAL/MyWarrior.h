// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyWarrior.generated.h"

UCLASS()
class CHAPTER_UNREAL_API AMyWarrior : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyWarrior();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector2D lastInput;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement functions

	void Forward(float amount);
	void Back(float amount);
	void Right(float amount);
	void Left(float amount);



};
