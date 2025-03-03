// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_BaseEntity.h"
#include "TD_Spawner.generated.h"

class USpawnComponent;

UCLASS()
class HWTOWERDEFENSE_API ATD_Spawner : public ATD_BaseEntity
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Enity|Component")
	TObjectPtr<UBillboardComponent> billbord = nullptr;
	UPROPERTY(EditAnywhere, Category= "Enity|Component")
	TObjectPtr<USpawnComponent> spawnComponent = nullptr;
	
public:
	FORCEINLINE TObjectPtr<USpawnComponent> GetSpawnComponent() const
	{
		return spawnComponent;
	}
public:	
	// Sets default values for this actor's properties
	ATD_Spawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DrawDebug();
	virtual bool ShouldTickIfViewportsOnly() const override;

};
