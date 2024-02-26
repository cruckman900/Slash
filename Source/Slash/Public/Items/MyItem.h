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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

private:
	float MovementRate = 50.f;
	float RotationRate = 45.f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
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
