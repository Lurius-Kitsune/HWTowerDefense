// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "SpawnComponent.h"
#include "GameFramework/Actor.h"
#include "TurretActor.generated.h"

class ASpawnEnemy;
UCLASS()
class HWTOWERDEFENSE_API ATurretActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Turret|Component")
	TObjectPtr<UStaticMeshComponent> mesh;
	UPROPERTY(EditAnywhere, Category = "Turret|Component")
	TObjectPtr<USpawnComponent> spawnerComponent;

	UPROPERTY(EditAnywhere, Category = "Turret|SpawnInfo")
	float fireRate = 5.0f;

	UPROPERTY(VisibleAnywhere, Category = "Turret|SpawnInfo")
	FTimerHandle spawnTimer;

	UPROPERTY(EditAnywhere, Category = "Turret|Debug")
	bool useDebug = false;

	UPROPERTY(EditAnywhere, Category = "Turret|Data")
	float range = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Turret|Data")
	TSubclassOf<AActor> targetClass;

	UPROPERTY(VisibleAnywhere, Category = "Turret|Debug")
	TArray<AEnemy*> targets;

	UPROPERTY(EditAnywhere, Category = "Turret|Data")
	TSubclassOf<AActor> spawnerClass;

	UPROPERTY(VisibleAnywhere, Category = "Turret|Debug")
	TObjectPtr<ASpawnEnemy> enemySpawner;

	UPROPERTY(EditAnywhere, Category = "Turret|Debug")
	bool canShoot = true;

	UPROPERTY(VisibleAnywhere, Category = "Turret|Debug")
	TObjectPtr<AEnemy> target;

public:
	FORCEINLINE void ToogleShoot()
	{
		canShoot = true;
	}
	UFUNCTION() FORCEINLINE void AddTarget(AActor* _actor)
	{
		if (AEnemy* _enemy = Cast<AEnemy>(_actor))
			targets.Add(_enemy);
	}

public:	
	// Sets default values for this actor's properties
	ATurretActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION() void RemoveTarget();

private:
	void Init();

	void DrawDebug();
	void Action();
	bool IsEnnemyInRange();

	UFUNCTION() void Shoot(AActor* _actor);

};
