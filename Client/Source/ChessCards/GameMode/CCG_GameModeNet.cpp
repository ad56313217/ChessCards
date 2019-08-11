// Fill out your copyright notice in the Description page of Project Settings.


#include "CCG_GameModeNet.h"


ACCG_GameModeNet::ACCG_GameModeNet()
{
	//Url = "101.132.149.251";
	Url = "101.132.149.251";
	Port = 8888;
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

	if (TcpM)
	{
		TcpM->SocketCreate(Url, Port);

		GetWorldTimerManager().SetTimer(Timer, this, &ACCG_GameModeNet::ReceiveMes, 1.f, true, 1.f);
	}
	
}

ACCG_TCPManager* ACCG_GameModeNet::CreateTCPManager()
{
	return GetWorld()->SpawnActor<ACCG_TCPManager>();
}

void ACCG_GameModeNet::TCP_SendMes(FString DataIn)
{
	if (TcpM)
	{
		TcpM->SocketSend(DataIn);
	}
}

void ACCG_GameModeNet::ReceiveMes()
{
	if (TcpM)
	{
		bool isReceive;
		FString mesInfo;
		TcpM->SocketReceive(isReceive, mesInfo);
	}
}