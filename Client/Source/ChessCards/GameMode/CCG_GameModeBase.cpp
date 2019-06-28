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

	CreateMainPage();
}

void ACCG_GameModeBase::CreateMainPage()
{
	FString pageName = "WidgetBlueprint'/Game/UI/Main/MainPage.MainPage_C'";
	TSubclassOf<UUserWidget> widgetClass = LoadClass<UUserWidget>(NULL, *pageName);
	UCCG_MainPage* mainpage = CreateWidget<UCCG_MainPage>(GetWorld(), widgetClass);
	if (mainpage)
	{
		mainpage->AddToViewport(0);
	}
}