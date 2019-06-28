// Fill out your copyright notice in the Description page of Project Settings.


#include "CCG_PageBase.h"
#include "WidgetTree.h"
#include "Button.h"
#include "Kismet/KismetStringLibrary.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include <CheckBox.h>
#include <Slider.h>
#include <ComboBoxString.h>
#include <ComboBox.h>


UCCG_PageBase::UCCG_PageBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}
UCCG_PageBase::~UCCG_PageBase()
{
}


/**初始化*/
bool UCCG_PageBase::Initialize()
{
	bool initRtn = Super::Initialize();
	if (!initRtn)
	{
		return false;
	}
	return true;
}

/**引擎销毁会调用此方法*/
void UCCG_PageBase::BeginDestroy()
{
	Super::BeginDestroy();
}

/**
* 添加/移除界面
* @param bool bShow
*/
void UCCG_PageBase::Show(bool bShow)
{
	m_isShow = bShow;
	UE_LOG(LogTemp, Log, TEXT("UMXUserWidget Show:%d, InView:%d"), IsShow() ? 1 : 0, IsInViewport() ? 1 : 0);
	if (IsShow())
	{
		if (IsInViewport())
		{
			this->RemoveFromParent();
			FTimerHandle TimerHandle;
			//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UMXUserWidget::DelayAddToViewport, 0.000001f, false);
		}
		else
			AddToViewport();
	}
	else
	{
		this->RemoveFromParent();
	}
}

/**
* 判断界面是否已添加
* @return bool. true:已添加, false:未添加
*/
bool UCCG_PageBase::IsShow() const
{
	return m_isShow;
}


void UCCG_PageBase::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCCG_PageBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

