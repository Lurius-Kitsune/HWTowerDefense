// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_StaticEntity.h"
#include "TD_TOWER.generated.h"

class UTD_AttackComponent;

UCLASS()
class HWTOWERDEFENSE_API ATD_Tower : public ATD_StaticEntity
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Entity|Components");
	TObjectPtr<UTD_AttackComponent> attackComponent = nullptr;

public:	
	// Sets default values for this actor's properties
	ATD_Tower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void DrawDebug();

};
