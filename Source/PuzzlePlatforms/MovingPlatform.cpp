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
    GlobalStartLocation = GetActorLocation();
    GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HasAuthority())
    {
        FVector Location = GetActorLocation();
        // FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
        float JourneyLength = (GlobalTargetLocation-GlobalStartLocation).Size();
        float JourneyTravelled = (Location-GlobalStartLocation).Size();
        if (JourneyTravelled >= JourneyLength)
        {
            GlobalTargetLocation = GlobalStartLocation;
            GlobalStartLocation = GetActorLocation();
            // FVector Swap = GlobalStartLocaiton;
            // GlobalStartLocation = GlobalTargetLocation;
            // GlobalTargetLocation = Swap;
            // FVector Direction = (GlobalTargetLocation-GlobalStartLocation).GetSafeNormal();

        }
        FVector Direction = (GlobalTargetLocation-Location).GetSafeNormal();

        Location += Speed*DeltaTime*Direction;
        SetActorLocation(Location);
    }

    
}

