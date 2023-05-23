// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWarrior.h"
#include "Components/InputComponent.h"

// Sets default values
AMyWarrior::AMyWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	lastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AMyWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyWarrior::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	float len = lastInput.Size();

	if (len > 1.0f) {
		lastInput /= len;
	}

	AddMovementInput(GetActorForwardVector(), lastInput.Y);
	AddMovementInput(GetActorRightVector(), lastInput.X);


	lastInput = FVector2D(0.0f, 0.0f);

}

// Called to bind functionality to input
void AMyWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AMyWarrior::Forward);
	PlayerInputComponent->BindAxis("Back", this, &AMyWarrior::Back);
	PlayerInputComponent->BindAxis("Right", this, &AMyWarrior::Right);
	PlayerInputComponent->BindAxis("Left", this, &AMyWarrior::Left);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyWarrior::Jump);

}

void AMyWarrior::Forward(float amount) {
	AddMovementInput(GetActorForwardVector(), amount);
	lastInput.Y += amount;
}


void AMyWarrior::Back(float amount) {
	AddMovementInput(-GetActorForwardVector(), amount);
	lastInput.Y -= amount;
}

void AMyWarrior::Right(float amount) {
	AddMovementInput(GetActorRightVector(), amount);
	lastInput.X += amount;
}

void AMyWarrior::Left(float amount) {
	AddMovementInput(-GetActorRightVector(), amount);
	lastInput.X -= amount;
}
