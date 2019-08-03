// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCG_GameModeBase.h"
#include "Net/CCG_TCPManager.h"
#include "CCG_GameModeNet.generated.h"

/**
*
*/
UCLASS()
class CHESSCARDS_API ACCG_GameModeNet : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACCG_GameModeNet();
	virtual void Tick(float DeltaTime) override;
	// Called when the game starts
	virtual void BeginPlay() override;

	ACCG_TCPManager* CreateTCPManager();

	void TCP_SendMes(FString DataIn);
public:
	ACCG_TCPManager * TcpM;

	FString Url;

	int32 Port;
};