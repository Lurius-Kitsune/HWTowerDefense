// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HWTOWERDEFENSE_API USpawnComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY();
	AActor* owner;

	UPROPERTY(EditAnywhere, Category = "Spawn|SpawnInfo")
	TSubclassOf<AActor> actorToSpawn = nullptr;

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

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Spawn();
};
