// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/CCG_PageBase.h"
#include "Controller/CCG_ControllerLogin.h"
#include "CCG_LoginPage.generated.h"

/**
 * 
 */
UCLASS()
class CHESSCARDS_API UCCG_LoginPage : public UCCG_PageBase
{
	GENERATED_BODY()
public:
	/**初始化*/
	virtual bool Initialize() override;

protected:
	//游戏开始入口
	virtual void NativeConstruct();
	//主循环
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
	//监听事件
	UFUNCTION()
		void AddEventListening();
	UFUNCTION()
		void Logon_Btf();
	UFUNCTION()
		void Register_Btf();
public:
	UPROPERTY(Meta = (BindWidget))
		class UButton* LogonButton;
	UPROPERTY(Meta = (BindWidget))
		class UButton* RegisterButton;

	UPROPERTY(BlueprintReadWrite, Category = "Login")
	FString NameStr;
	UPROPERTY(BlueprintReadWrite, Category = "Login")
	FString PWStr;
private:
	ACCG_ControllerLogin* GetControllerLogin();
};
