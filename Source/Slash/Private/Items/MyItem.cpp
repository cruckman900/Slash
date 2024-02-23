// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MyItem.h"
#include "DrawDebugHelpers.h"
#include "Slash/Slash.h"

#define THIRTY 30

// Sets default values
AMyItem::AMyItem()
{
	// Pre-packaged bool to determine if timer should tick
	PrimaryActorTick.bCanEverTick = true;
}

void AMyItem::BeginPlay()
{
	Super::BeginPlay();
	
	// Variables for finding the world and vector values for location and direction of objects in the world
	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	if (World)
	{
		// Define and show debug objects for this instanced item
		FColor Color = FColor::Cyan;
		DRAW_SPHERE(Location, Color);
		DRAW_LINE(Location, Location + Forward * 100.f, Color);
	}
}

void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

