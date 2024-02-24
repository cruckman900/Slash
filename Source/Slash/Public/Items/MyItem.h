// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

UCLASS()
class SLASH_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	float MovementRate;
	float RotationRate;
	float RunningTime;
	float DeltaZ;

	FVector Location;
	FVector Forward;
	FVector Right;
	FVector Up;

	FColor Color;
	FColor ColorForward;
	FColor ColorRight;
	FColor ColorUp;

};
