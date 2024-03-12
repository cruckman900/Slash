// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SlashAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API USlashAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BluePrintReadOnly)
	class ASlashCharacter* SlashCharacter;

	UPROPERTY(BluePrintReadOnly, Category = Movement)
	class UCharacterMovementComponent* SlashCharacterMovement;

	UPROPERTY(BluePrintReadOnly, Category = Movement)
	float GroundSpeed;

	UPROPERTY(BluePrintReadOnly, Category = Movement)
	bool IsFalling;

};
