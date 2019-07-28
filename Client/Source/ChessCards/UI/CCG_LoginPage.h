// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/CCG_PageBase.h"
#include "CCG_LoginPage.generated.h"

/**
 * 
 */
UCLASS()
class CHESSCARDS_API UCCG_LoginPage : public UCCG_PageBase
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
		void Logon_Btf();
public:
	UPROPERTY(Meta = (BindWidget))
		class UButton* LogonButton;
};
