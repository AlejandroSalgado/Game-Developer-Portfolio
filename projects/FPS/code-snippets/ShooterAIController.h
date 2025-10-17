// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;
protected:
	virtual void BeginPlay() override;
private: 
	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 500;
	APawn* PlayerPawn;
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
