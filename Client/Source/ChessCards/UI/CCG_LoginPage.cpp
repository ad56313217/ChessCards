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
	if (RegisterButton)
	{
		RegisterButton->OnClicked.AddDynamic(this, &UCCG_LoginPage::Register_Btf);
	}
}

void UCCG_LoginPage::Logon_Btf()
{
	ACCG_ControllerLogin* _c = GetControllerLogin();
	if (_c)
	{
		FString _d = "login,login,";
		_d += NameStr;
		_d += ",";
		_d += PWStr;
		_c->Login(_d);
	}

}

void UCCG_LoginPage::Register_Btf()
{
	ACCG_ControllerLogin* _c = GetControllerLogin();
	if (_c)
	{
		FString _d = "login,register,";
		_d += NameStr;
		_d += ",";
		_d += PWStr;
		_c->Login(_d);
	}

}

ACCG_ControllerLogin* UCCG_LoginPage::GetControllerLogin()
{
	ACCG_ControllerLogin* _c = Cast<ACCG_ControllerLogin>(GetWorld()->GetFirstPlayerController());
	return _c;
}