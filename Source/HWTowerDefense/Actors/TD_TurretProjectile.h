// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "TD_MouvementComponent.h"
#include "TD_TurretProjectile.generated.h"

UCLASS()
class HWTOWERDEFENSE_API ATD_TurretProjectile : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "TurretProjectile|Component")
	TObjectPtr<UStaticMeshComponent> mesh;

	UPROPERTY(EditAnywhere, Category = "TurretProjectile|Debug")
	bool useDebug = false;

	UPROPERTY(EditAnywhere, Category = "TurretProjectile|Component")
	TObjectPtr<UTD_MouvementComponent> movement;

	UPROPERTY(EditAnywhere, Category = "TurretProjectile|Data")
	float damage = 50.0f;

	UPROPERTY(EditAnywhere, Category = "TurretProjectile|Data")
	TObjectPtr<AEnemy> target;
	
public:
	FORCEINLINE TObjectPtr<UTD_MouvementComponent> GetMovement() const
	{
		return movement;
	}
	FORCEINLINE void SetTarget(AActor* _actor)
	{
		movement->SetWaypoints({ _actor });
		if (AEnemy* _enemy = Cast<AEnemy>(_actor))
		{
			target = _enemy;
			_enemy->GetMovement()->OnTrackFinish().AddDynamic(this, &ATD_TurretProjectile::MissTarget);
			_enemy->GetLife()->OnDeath().AddDynamic(this, &ATD_TurretProjectile::MissTarget);
		}
	}

public:	
	// Sets default values for this actor's properties
	ATD_TurretProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION() void HitTarget();
	UFUNCTION() void MissTarget();

private:
	void Init();

	void DrawDebug();
};
