// Fill out your copyright notice in the Description page of Project Settings.


#include "CCG_GameModeBase.h"


ACCG_GameModeBase::ACCG_GameModeBase()
{
}

void ACCG_GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACCG_GameModeBase::BeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("ACCG_GameModeBase | BeginPlay"));

	Super::BeginPlay();
}
