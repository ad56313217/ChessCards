// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/TCPSocketClient.h"
#include "Protobuf/bin/addressbook.pb.h"
#include "CCG_TCPManager.generated.h"

/**
 * 
 */
UCLASS()
class CHESSCARDS_API ACCG_TCPManager : public ATCPSocketClient
{
	GENERATED_BODY()
	
		virtual void MesReceive(bool bReceive, FString recvMessage) override;
};
