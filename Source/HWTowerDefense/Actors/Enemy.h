// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TD_MouvementComponent.h"
#include "TD_LifeComponent.h"
#include "Enemy.generated.h"

UCLASS()
class HWTOWERDEFENSE_API AEnemy : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Enemy|Component")
	TObjectPtr<UStaticMeshComponent> mesh;

	UPROPERTY(EditAnywhere, Category = "Enemy|Component")
	TObjectPtr<UTD_MouvementComponent> movement;

	UPROPERTY(EditAnywhere, Category = "Enemy|Component")
	TObjectPtr<UTD_LifeComponent> life;

	UPROPERTY(EditAnywhere, Category = "Enemy|Debug")
	bool useDebug = false;
	
public:
	FORCEINLINE TObjectPtr<UTD_MouvementComponent> GetMovement() const
	{
		return movement;
	}
	FORCEINLINE TObjectPtr<UTD_LifeComponent> GetLife() const
	{
		return life;
	}

public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void DrawDebug();
	UFUNCTION() void FinishedTrack();

};
