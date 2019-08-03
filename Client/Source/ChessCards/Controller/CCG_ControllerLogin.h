// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCG_ControllerBase.h"
#include "GameMode/CCG_GameModeNet.h"
#include "CCG_ControllerLogin.generated.h"

/**
 * 
 */
UCLASS()
class CHESSCARDS_API ACCG_ControllerLogin : public ACCG_ControllerBase
{
	GENERATED_BODY()
	
public:
	void Login(FString DataIn);

private:
	ACCG_GameModeNet* GetGameModeNet();
};
