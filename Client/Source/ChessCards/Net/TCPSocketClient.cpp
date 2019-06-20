#include "TCPSocketClient.h"

// Sets default values
ATCPSocketClient::ATCPSocketClient()
{
	SocketClient = NULL;
}

void ATCPSocketClient::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (SocketClient)
	{
		//关闭，销毁
		SocketClient->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SocketClient);
	}
}

bool ATCPSocketClient::SocketCreate(FString IPStr, int32 port)
{
	FIPv4Address::Parse(IPStr, ip);

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);

	SocketClient = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

	if (SocketClient->Connect(*addr))
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("Connect Succ!"));
		UE_LOG(LogTemp, Warning, TEXT("Connect Succ!"));
		return true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("Connect failed!"));
		UE_LOG(LogTemp, Warning, TEXT("Connect failed!"));
		return false;
	}
}

void ATCPSocketClient::SocketSend(FString meesage)
{
	TCHAR *seriallizedChar = meesage.GetCharArray().GetData();
	int32 size = FCString::Strlen(seriallizedChar) + 1;
	int32 sent = 0;

	if (SocketClient->Send((uint8*)TCHAR_TO_UTF8(seriallizedChar), size, sent))
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send Succ!"));
		UE_LOG(LogTemp, Warning, TEXT("_____Send Succ!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, TEXT("_____Send failed!"));
		UE_LOG(LogTemp, Warning, TEXT("_____Send failed!"));
	}
}

void ATCPSocketClient::SocketReceive(bool & bReceive, FString & recvMessage)
{
	recvMessage = "";
	bReceive = false;
	if (!SocketClient)
	{
		return;
	}

	TArray<uint8> ReceiveData;
	uint32 size;
	uint8 element = 0;
	while (SocketClient->HasPendingData(size))
	{
		ReceiveData.Init(element, FMath::Min(size, 65507u));

		int32 read = 0;
		SocketClient->Recv(ReceiveData.GetData(), ReceiveData.Num(), read);

	}

	if (ReceiveData.Num() <= 0)
	{
		return;
	}
	FString log = "Total Data read! num: " + FString::FromInt(ReceiveData.Num() <= 0);

	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, log);
	UE_LOG(LogTemp, Warning, TEXT("Recv log:   %s"), *log);

	const FString ReceivedUE4String = StringFromBinaryArray(ReceiveData);

	log = "Server:" + ReceivedUE4String;
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, log);
	UE_LOG(LogTemp, Warning, TEXT("*** %s"), *log);

	recvMessage = ReceivedUE4String;

	bReceive = true;
}

FString ATCPSocketClient::StringFromBinaryArray(TArray<uint8> BinaryArray)
{
	return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}