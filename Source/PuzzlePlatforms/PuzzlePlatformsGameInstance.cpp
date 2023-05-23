// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

#include "Engine/Engine.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UPuzzlePlatformsGameInstance::init()
{
    UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));    
}

void UPuzzlePlatformsGameInstance::Host()
{
    UEngine* Engine = GetEngine();
    if (!ensure(Engine != nullptr)) return;

    Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));
    Uworld* World = GetWorld();
    if (!ensure(World!=nullptr)) return;

    World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThridPersonExampleMap");
}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
    UEngine* Engine = GetEngine();
    if (!ensure(Engine != nullptr)) return;

    Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
}
