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

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<ATD_BaseEntity> actorToSpawn = nullptr;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawn, AActor*, _actor);
	UPROPERTY()
	FOnSpawn onSpawn;

public:
	FORCEINLINE FOnSpawn& GetOnSpawn()
	{
		return onSpawn;
	}	
public:	
	// Sets default values for this component's properties
	USpawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	
	void Spawn();
};
