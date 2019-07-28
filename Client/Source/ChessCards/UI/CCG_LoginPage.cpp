// Fill out your copyright notice in the Description page of Project Settings.


#include "CCG_LoginPage.h"
#include "Button.h"
/**³õÊ¼»¯*/
bool UCCG_LoginPage::Initialize()
{
	bool initRtn = Super::Initialize();
	if (!initRtn)
	{
		return false;
	}
	return true;
}

void UCCG_LoginPage::NativeConstruct()
{
	Super::NativeConstruct();

	AddEventListening();
}

void UCCG_LoginPage::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UCCG_LoginPage::AddEventListening()
{
	if (LogonButton)
	{
		LogonButton->OnClicked.AddDynamic(this, &UCCG_LoginPage::Logon_Btf);
	}
}

void UCCG_LoginPage::Logon_Btf()
{

}