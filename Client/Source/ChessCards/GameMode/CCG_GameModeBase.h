// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UI/CCG_MainPage.h"
#include "CCG_GameModeBase.generated.h"

/**
 *
 */
UCLASS()
class CHESSCARDS_API ACCG_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACCG_GameModeBase();
	virtual void Tick(float DeltaTime) override;
	// Called when the game starts
	virtual void BeginPlay() override;

	void CreateMainPage();
};