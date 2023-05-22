// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Chapter_UNREALGameModeBase.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor);
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)
UCLASS()
class CHAPTER_UNREAL_API AChapter_UNREALGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void BeginPlay();

	FStandardDelegateSignature MyStandardDelegate;

	FParamDelegateSignature MyParamaterDelegate;

	FMulticastDelegateSignature MyMulticastDelegate;
	
};
