// Fill out your copyright notice in the Description page of Project Settings.


#include "CCG_GameModeLogin.h"


ACCG_GameModeLogin::ACCG_GameModeLogin()
{
}

void ACCG_GameModeLogin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACCG_GameModeLogin::BeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("ACCG_GameModeLogin | BeginPlay"));

	Super::BeginPlay();

	CreateMainPage();
}

void ACCG_GameModeLogin::CreateMainPage()
{
	FString pageName = "WidgetBlueprint'/Game/UI/Main/MainPage.MainPage_C'";
	TSubclassOf<UUserWidget> widgetClass = LoadClass<UUserWidget>(NULL, *pageName);
	UCCG_MainPage* mainpage = CreateWidget<UCCG_MainPage>(GetWorld(), widgetClass);
	if (mainpage)
	{
		mainpage->AddToViewport(0);
	}
}