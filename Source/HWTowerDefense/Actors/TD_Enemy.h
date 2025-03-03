// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_StaticEntity.h"
#include "TD_Enemy.generated.h"

UCLASS()
class HWTOWERDEFENSE_API ATD_Enemy : public ATD_StaticEntity
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Entity|Components")
	TObjectPtr<UTD_MovementComponent> movement = nullptr;

public:
	FORCEINLINE TObjectPtr<UStaticMeshComponent> GetMesh() const { return mesh; }

public:	
	// Sets default values for this actor's properties
	ATD_Enemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
