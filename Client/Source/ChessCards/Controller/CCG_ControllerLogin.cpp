// Fill out your copyright notice in the Description page of Project Settings.


#include "CCG_ControllerLogin.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void ACCG_ControllerLogin::Login(FString DataIn)
{
	ACCG_GameModeNet* _gm = GetGameModeNet();
	if (_gm)
	{
		_gm->TCP_SendMes(DataIn);
	}
}

ACCG_GameModeNet*ACCG_ControllerLogin::GetGameModeNet()
{
	return Cast<ACCG_GameModeNet>(UGameplayStatics::GetGameMode(GetWorld()));
}