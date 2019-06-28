// Fill out your copyright notice in the Description page of Project Settings.
//	������

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
	/**��ʼ��*/
	virtual bool Initialize() override;

protected:
	//��Ϸ��ʼ���
	virtual void NativeConstruct();
	//��ѭ��
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
	//�����¼�
	UFUNCTION()
		void AddEventListening();

	UFUNCTION()
		void Start_Btf();
public:
	UPROPERTY(Meta = (BindWidget))
		class UButton* StartButton;
};
