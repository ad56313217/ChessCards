#include "TCPSocketServer.h"

// Sets default values
ATCPSocketServer::ATCPSocketServer()
{
	//初始化
	SocketServer = NULL;
	SocketClient = NULL;
}

void ATCPSocketServer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (SocketServer)
	{
		//关闭，销毁
		SocketServer->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketServer);
	}
	if (SocketClient)
	{
		//关闭，销毁
		SocketClient->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketClient);
	}
}

bool ATCPSocketServer::createSoc()
{
	SocketServer = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	if (!SocketServer) {
		return false;
	}
	// SocketServer.SetNonBlocking(false);
	//SocketServer->SetNonBlocking(false);
	return true;
}

bool ATCPSocketServer::bindSoc(const FString & TheIP, const int32 ThePort)
{
	FIPv4Address::Parse(TheIP, ip);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(ThePort);
	bool bBind = SocketServer->Bind(*addr);
	return bBind;
}

bool ATCPSocketServer::listenSoc(const int32 MaxBacklog)
{
	bool bListen = SocketServer->Listen(MaxBacklog);
	return bListen;
}

bool ATCPSocketServer::acceptSoc(const FString & TheIP, const int32 ThePort)
{
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	FIPv4Address::Parse(TheIP, ip);
	targetAddr->SetIp(ip.Value);
	targetAddr->SetPort(ThePort);
	SocketClient = SocketServer->Accept(*targetAddr, "aaa");
	if (!SocketClient)
		return false;
	return true;
}

bool ATCPSocketServer::sendSoc(const FString & sendMessage)
{
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//FIPv4Address::Parse(TheIP, ip);
	//targetAddr->SetIp(ip.Value);
	//targetAddr->SetPort(ThePort);

	FString serialized = sendMessage;

	bool bsend;
	TCHAR *seriallizedChar = serialized.GetCharArray().GetData();
	int32 size = FCString::Strlen(seriallizedChar) + 1;
	int32 sent = 0;
	//注意，要用客户端这个socket
	bsend = SocketClient->SendTo((uint8*)TCHAR_TO_UTF8(seriallizedChar), size, sent, *targetAddr);

	if (bsend)
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send Succ!"));
		UE_LOG(LogTemp, Warning, TEXT("_____Send Succ!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send failed!"));
		UE_LOG(LogTemp, Warning, TEXT("_____Send failed!"));
	}
	return bsend;
}

void ATCPSocketServer::recvSoc()
{
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	TArray<uint8> ReceivedData;//定义一个接收器
	uint32 Size;
	//注意，要用客户端这个socket
	if (SocketClient->HasPendingData(Size))
	{
		uint8 *Recv = new uint8[Size];
		int32 BytesRead = 0;
		//将数组调整到给定数量的元素。 新元素将被初始化。
		ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));
		//注意，要用客户端这个socket
		SocketClient->RecvFrom(ReceivedData.GetData(), ReceivedData.Num(), BytesRead, *targetAddr);
		if (ReceivedData.Num() > 0)
		{
			//打印
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Data Bytes Read ~> %d"), ReceivedData.Num()));
			FString ReceivedUE4String = StringFromBinaryArray(ReceivedData);
			GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, FString::Printf(TEXT("As String Data ~> %s"), *ReceivedUE4String));
			//判断是否发送了相对的指令，进行对应事件调用
			if (ReceivedUE4String.Equals("jiegege"))
			{
				sendSoc("server auto send ");
			}



		}
	}
}

FString ATCPSocketServer::StringFromBinaryArray(const TArray<uint8>& BinaryArray)
{
	return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}