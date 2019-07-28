// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCG_GameModeNet.h"
#include "UI/CCG_MainPage.h"
#include "CCG_GameModeLogin.generated.h"

/**
*
*/
UCLASS()
class CHESSCARDS_API ACCG_GameModeLogin : public ACCG_GameModeNet
{
	GENERATED_BODY()

public:
	ACCG_GameModeLogin();

	virtual void Tick(float DeltaTime) override;
	// Called when the game starts
	virtual void BeginPlay() override;

	void CreateMainPage();
};