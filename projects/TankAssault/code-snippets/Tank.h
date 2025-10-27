// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * Tank pawn class for player control.
 */
class USpringArmComponent;
class UCameraComponent;
class UInputComponent;
class APlayerController;

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void HandleDestruction();
	APlayerController* GetTankPlayerController() const {return TankPlayerController;}

	/** Flag for checking if Tank died. Returns whether the tank is alive */
	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category="Movement")
	float TankSpeed = 500.f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate = 120.f;
	
	UPROPERTY()
	APlayerController* TankPlayerController = nullptr;

	void Move(float Value);
	void Turn(float Value);
};
