// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

/**��ʼ��*/
bool UMyUserWidget::Initialize()
{
	bool initRtn = Super::Initialize();
	if (!initRtn)
	{
		return false;
	}
	return true;
}