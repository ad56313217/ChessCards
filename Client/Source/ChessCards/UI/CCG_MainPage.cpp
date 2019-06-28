// Fill out your copyright notice in the Description page of Project Settings.

#include "CCG_MainPage.h"
#include "Button.h"
/**≥ı ºªØ*/
bool UCCG_MainPage::Initialize()
{
	bool initRtn = Super::Initialize();
	if (!initRtn)
	{
		return false;
	}
	return true;
}

void UCCG_MainPage::NativeConstruct()
{
	Super::NativeConstruct();

	AddEventListening();
}

void UCCG_MainPage::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UCCG_MainPage::AddEventListening()
{
	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UCCG_MainPage::Start_Btf);
	}
}

void UCCG_MainPage::Start_Btf()
{
	//¥Ú”°log
	UE_LOG(LogTemp, Log, TEXT("UCCG_MainPage | Start_Btf"));
}