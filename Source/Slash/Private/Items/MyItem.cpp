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
	FVector Right = GetActorRightVector();
	FVector Up = GetActorUpVector();

	if (World)
	{
		// Define and show debug objects for this instanced item
		FColor Color = FColor::Silver;
		FColor ColorForward = FColor::Green;
		FColor ColorRight = FColor::Red;
		FColor ColorUp = FColor::Blue;

		DRAW_SPHERE(Location, Color);

		// Using individual calls to set up line + endpoint for forward vector
		DRAW_LINE(Location, Location + Forward * 100.f, ColorForward);
		DRAW_POINT(Location + Forward * 100.f, ColorForward);

		// Using single call to draw vectors
		DRAW_VECTOR(Location, Location + Right * 50.f, ColorRight);
		DRAW_VECTOR(Location, Location + Up * 50.f, ColorUp);
	}
}

void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

