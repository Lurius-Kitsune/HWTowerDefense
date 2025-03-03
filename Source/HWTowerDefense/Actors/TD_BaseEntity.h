// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TD_BaseEntity.generated.h"

UCLASS(Abstract)
class HWTOWERDEFENSE_API ATD_BaseEntity : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Enemy|Debug")
	bool useDebug = false;

public:	
	// Sets default values for this actor's properties
	ATD_BaseEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void DrawDebug() PURE_VIRTUAL(ATD_BaseEntity::DrawDebug, );
	virtual void Tick(float DeltaTime) override;

};
