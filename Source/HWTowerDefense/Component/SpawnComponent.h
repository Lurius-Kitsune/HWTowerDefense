// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_BaseComponent.h"

#include "SpawnComponent.generated.h"
class ATD_BaseEntity;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HWTOWERDEFENSE_API USpawnComponent : public UTD_BaseComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawn, AActor*, _actor);
	UPROPERTY()
	FOnSpawn onSpawn;

	UPROPERTY(EditAnywhere, Category = "Spawn|Spawn")
	bool canSpawn = true;
	UPROPERTY(EditAnywhere, Category = "Spawn|Spawn")
	TSubclassOf<ATD_BaseEntity> actorToSpawn = nullptr;
	UPROPERTY(EditAnywhere, Category = "Spawn|Spawn")
	float spawnRate = 1.5f;
	UPROPERTY(EditAnywhere, Category = "Spawn|Spawn")
	FVector spawnLocation = FVector(0);
	UPROPERTY(VisibleAnywhere, Category = "Spawn|Debug")
	int amountSpawner = 0;
	UPROPERTY(VisibleAnywhere, Category = "Spawn|Debug")
	TArray<TObjectPtr<ATD_BaseEntity>> allSpawned;
	UPROPERTY(EditAnywhere, Category = "Spawn|Spawn")
	TArray<FVector> path;

	FTimerHandle spawnTimerHandle;

public:
	FORCEINLINE FOnSpawn& GetOnSpawn()
	{
		return onSpawn;
	}	
	FORCEINLINE TArray<TObjectPtr<ATD_BaseEntity>>& GetAllSpawned()
	{
		return allSpawned;
	}
	FORCEINLINE TArray<FVector>& GetPath()
	{
		return path;
	}
	FORCEINLINE void SetPath(const TArray<FVector>& _path)
	{
		path = _path;
	}
	FORCEINLINE void SetCanSpawn(const bool _canSpawn)
	{
		canSpawn = _canSpawn;
	}
public:	
	// Sets default values for this component's properties
	USpawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Init() override;
	
public:	
	void Spawn();
	virtual void DrawDebug() override;
};
