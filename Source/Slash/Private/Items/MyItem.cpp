// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MyItem.h"
#include "Slash/DebugMacros.h"

// Sets default values
AMyItem::AMyItem()
{
	// Pre-packaged bool to determine if timer should tick
	PrimaryActorTick.bCanEverTick = true;
}

int RandomNumber = rand() % 2000000 + 1;

void AMyItem::BeginPlay()
{
	Super::BeginPlay();
}

void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// SetActorLocation(FVector(0.f, 0.f, 100.f));
	// SetActorRotation(FRotator(0.f, 45.f, 0.f));

	// Movement rate in units of cm/s
	MovementRate = 50.f;
	RotationRate = 45.f;
	// Rate (cm/s) * DeltaTime (s/frame) = (cm/frame)
	// AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));

	RunningTime += DeltaTime;
	DeltaZ = 0.25f * FMath::Sin(RunningTime * 5.f);
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	Location = GetActorLocation();
	Forward = GetActorForwardVector();
	Right = GetActorRightVector();
	Up = GetActorUpVector();

	Color = FColor::Silver;
	ColorForward = FColor::Red;
	ColorRight = FColor::Green;
	ColorUp = FColor::Blue;

	if (GetWorld())
	{
		const FString MyStringPrintf = FString::Printf(TEXT("Item {0}: at coords ({1}, {2}, {3})"));
		const FString MyStringFormatted = FString::Format(*MyStringPrintf, { GetName(), Location.X, Location.Y, Location.Z });
		PRINT_TO_SCREEN(RandomNumber, FColor::Cyan, *MyStringFormatted);

		// Define and show debug objects for this instanced item
		DRAW_SPHERE_SingleFrame(Location, Color);

		// Using individual calls to set up line + endpoint for forward vector
		DRAW_LINE_SingleFrame(Location, Location + Forward * 100.f, ColorForward);
		DRAW_POINT_SingleFrame(Location + Forward * 100.f, ColorForward);

		// Using single call to draw vectors
		DRAW_VECTOR_SingleFrame(Location, Location + Right * 50.f, ColorRight);
		DRAW_VECTOR_SingleFrame(Location, Location + Up * 50.f, ColorUp);
	}
}
