// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TD_LifeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HWTOWERDEFENSE_API UTD_LifeComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	AActor* owner;

	UPROPERTY(EditAnywhere, Category = "Life|Data")
	float lifePoints = 100.0f;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
	UPROPERTY()
	FOnDeath onDeath;


public:
	FORCEINLINE void SetLifePoints(const float _lifePoints)
	{
		if (_lifePoints <= 0)
		{
			Death();
		}
		lifePoints = _lifePoints;
	}
	FORCEINLINE void AddLifePoints(const float _lifePoints)
	{
		SetLifePoints(lifePoints + _lifePoints);
	}
	FORCEINLINE void RemoveLifePoints(const float _lifePoints)
	{
		SetLifePoints(lifePoints - _lifePoints);
	}
	FORCEINLINE FOnDeath& OnDeath()
	{
		return onDeath;
	}
public:	
	// Sets default values for this component's properties
	UTD_LifeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void Death();
		
};
