// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Runtime/Networking/Public/Networking.h"
#include "TCPSocketClient.generated.h"
///**
// *
// */
UCLASS()
class CHESSCARDS_API ATCPSocketClient : public AActor
{
	GENERATED_BODY()
		public:
			// Sets default values for this actor's properties
			ATCPSocketClient();
		public:
			/** Called whenever this actor is being removed from a level */
			virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		
			UFUNCTION(BlueprintCallable, Category = "MySocket")
				bool SocketCreate(FString IPStr, int32 port);
		
			UFUNCTION(BlueprintCallable, Category = "MySocket")
				void SocketSend(FString meesage);
		
			UFUNCTION(BlueprintPure, Category = "MySocket")
				void SocketReceive(bool& bReceive, FString& recvMessage);
		
			virtual void MesReceive(bool bReceive, FString recvMessage);

			FString StringFromBinaryArray(TArray<uint8> BinaryArray);
		
			FSocket *SocketClient;
		
			FIPv4Address ip;
};
