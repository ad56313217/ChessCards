// Fill out your copyright notice in the Description page of Project Settings.
//	主界面

#pragma once

#include "CoreMinimal.h"
#include "UI/CCG_PageBase.h"
#include "CCG_MainPage.generated.h"

/**
 * 
 */
UCLASS()
class CHESSCARDS_API UCCG_MainPage : public UCCG_PageBase
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
		void Start_Btf();
public:
	UPROPERTY(Meta = (BindWidget))
		class UButton* StartButton;
};
