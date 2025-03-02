// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnComponent.h"
#include "SpawnEnemy.generated.h"

class ACheckpoint;

UCLASS()
class HWTOWERDEFENSE_API ASpawnEnemy : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Spawn|Component")
	TObjectPtr<UBillboardComponent> icon;

	UPROPERTY(EditAnywhere, Category = "Spawn|Component")
	TObjectPtr<USpawnComponent> spawnComponent;

	UPROPERTY(EditAnywhere, Category = "Spawn|Data")
	TArray<TObjectPtr<ACheckpoint>> checkpoints;
	
public:	
	// Sets default values for this actor's properties
	ASpawnEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	
	UFUNCTION() void SetCheckpointsToEnemy(AActor* _actor);
};
