// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMode/CCG_GameModeNet.h"
#include "CCG_PageBase.generated.h"
//
///**
// * 
// */
UCLASS()
class CHESSCARDS_API UCCG_PageBase : public UUserWidget
{
	GENERATED_BODY()
		//		public:
		//			/**初始化*/
		//			virtual bool Initialize() override;
		//};

public:
	UCCG_PageBase(const FObjectInitializer& ObjectInitializer);
	virtual ~UCCG_PageBase();

public:
	/**初始化*/
	virtual bool Initialize() override;

	/**引擎销毁会调用此方法*/
	virtual void BeginDestroy() override;

	/**
	* 添加/移除界面
	* @param bool bShow
	*/
	virtual void Show(bool bShow);

	/**
	* 判断界面是否已添加
	* @return bool. true:已添加, false:未添加
	*/
	bool IsShow() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My New User Widget")//界面名称
		FString MyNewWidgetName;

	//template<class TWidget>
	//TWidget* GetWidget(const FName& widgetName)
	//{
	//	TWidget* Widget = Cast<TWidget>(GetWidgetFromName(widgetName));
	//	if (Widget)
	//	{
	//		return Widget;
	//	}
	//	UE_LOG(LogTemp, Error, TEXT("[UI] Read Widget: %s , Failed"), *widgetName.ToString());
	//	return nullptr;
	//}

private:
	bool m_isShow;

protected:
	//游戏开始入口
	virtual void NativeConstruct();
	//主循环
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

	//ACCG_GameModeNet*GetGameModeNet();
};
