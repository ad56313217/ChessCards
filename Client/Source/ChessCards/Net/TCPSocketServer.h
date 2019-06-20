// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Runtime/Networking/Public/Networking.h"
#include "TCPSocketServer.generated.h"
///**
// *
// */
UCLASS()
class CHESSCARDS_API ATCPSocketServer : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ATCPSocketServer();
public:
	/** Called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable, Category = "MySocket")
		bool createSoc();
	UFUNCTION(BlueprintCallable, Category = "MySocket")
		bool bindSoc(const FString& TheIP, const int32 ThePort);
	UFUNCTION(BlueprintCallable, Category = "MySocket")
		bool listenSoc(const int32 MaxBacklog);
	UFUNCTION(BlueprintCallable, Category = "MySocket")
		bool acceptSoc(const FString& TheIP, const int32 ThePort);
	UFUNCTION(BlueprintCallable, Category = "MySocket")
		bool sendSoc(const FString& sendMessage);
	UFUNCTION(BlueprintCallable, Category = "MySocket")
		void recvSoc();
	FString StringFromBinaryArray(const TArray<uint8>& BinaryArray);

	FSocket* SocketServer;

	FSocket* SocketClient;

	FIPv4Address ip;
};