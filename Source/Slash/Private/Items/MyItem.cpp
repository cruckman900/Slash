// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/MyItem.h"
#include "Slash/DebugMacros.h"
#include "Components/SphereComponent.h"

AMyItem::AMyItem()
{
	PrimaryActorTick.bCanEverTick = true;

	Color = FColor::Silver;
	ColorForward = FColor::Red;
	ColorRight = FColor::Green;
	ColorUp = FColor::Blue;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AMyItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AMyItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AMyItem::OnSphereEndOverlap);
}

float AMyItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant); // period - 2*pi/K
}

float AMyItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant); // period - 2*pi/K
}

void AMyItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
	}
}

void AMyItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = FString("Ending Overlap with: ") + OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Blue, OtherActorName);
	}
}

void AMyItem::DrawDebugObjects()
{
	Location = GetActorLocation();
	Forward = GetActorForwardVector();
	Right = GetActorRightVector();
	Up = GetActorUpVector();

	// Define and show debug objects for this instanced item
	DRAW_SPHERE_SingleFrame(Location, Color);

	// Using individual calls to set up line + endpoint for forward vector
	DRAW_LINE_SingleFrame(Location, Location + Forward * 100.f, ColorForward);
	DRAW_POINT_SingleFrame(Location + Forward * 100.f, ColorForward);

	// Using single call to draw vectors
	DRAW_VECTOR_SingleFrame(Location, Location + Right * 50.f, ColorRight);
	DRAW_VECTOR_SingleFrame(Location, Location + Up * 50.f, ColorUp);
}

void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	/*
	if (GetWorld())
	{
		if (ShowDebugObjects)
		{
			DrawDebugObjects();
		}

		AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	}
	*/
}
