// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_StaticEntity.h"
#include "TD_Projectile.generated.h"

UCLASS()
class HWTOWERDEFENSE_API ATD_Projectile : public ATD_StaticEntity
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere)
	float moveSpeed = 100.0f;
	
public:
	FORCEINLINE void SetTarget(const TObjectPtr<AActor>& _actor)
	{
		target = _actor;
	}
public:	
	// Sets default values for this actor's properties
	ATD_Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void MoveTo(const float& _delta);

};
