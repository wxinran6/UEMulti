// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;
    SetReplicatingMovement(true);
    SetMobility(EComponentMobility::Movable);


}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority())
    {
        FVector Location = GetActorLocation();
        Location += FVector(Speed*DeltaTime, 0,0);
        SetActorLocation(Location);
    }

    
}
