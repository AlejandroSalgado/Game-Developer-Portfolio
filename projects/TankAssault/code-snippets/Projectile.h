// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

private:
	
	UPROPERTY(EditDefaultsOnly,Category="Combat")
	UStaticMeshComponent* Projectile;
	UPROPERTY(VisibleAnywhere,Category="Projectile Movement")
	class UProjectileMovementComponent* ProjectileMovementComp;
	UPROPERTY(EditDefaultsOnly,Category="Projectile Movement")
	float InitialSpeed = 10.f;
	UPROPERTY(EditDefaultsOnly,Category="Projectile Movement")
	float MaxSpeed = 100.f;
	UPROPERTY(EditAnywhere,Category="Combat")
	float Damage = 50.f;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherComponent, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category="Combat")
	class UParticleSystem* HitParticles;
	UPROPERTY(VisibleAnywhere, Category="Combat")
	class UParticleSystemComponent* TrailParticlesComponent;

	UPROPERTY(EditAnywhere, Category="Combat")
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, Category="Combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
