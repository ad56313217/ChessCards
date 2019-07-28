// Fill out your copyright notice in the Description page of Project Settings.


#include "CCG_GameModeNet.h"


ACCG_GameModeNet::ACCG_GameModeNet()
{
}

void ACCG_GameModeNet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACCG_GameModeNet::BeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("ACCG_GameModeNet | BeginPlay"));

	Super::BeginPlay();

	TcpM = CreateTCPManager();
}

ACCG_TCPManager* ACCG_GameModeNet::CreateTCPManager()
{
	return GetWorld()->SpawnActor<ACCG_TCPManager>();
}