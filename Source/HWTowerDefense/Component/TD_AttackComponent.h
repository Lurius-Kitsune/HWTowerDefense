// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_BaseComponent.h"
#include "TD_AttackComponent.generated.h"

class UTD_EnemyGISubsystem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HWTOWERDEFENSE_API UTD_AttackComponent : public UTD_BaseComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttack);
	UPROPERTY()
	FOnAttack onAttack;

	UPROPERTY();
	TObjectPtr<UTD_EnemyGISubsystem> enemySubsystem = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> projectileClass;
	UPROPERTY(EditAnywhere)
	bool canAttack = true;
	UPROPERTY(EditAnywhere)
	float range = 500.f;
	UPROPERTY(VisibleAnywhere)
	float currentTime = 0;
	UPROPERTY(EditAnywhere)
	float fireRate = 3.f;
	UPROPERTY(EditAnywhere)
	float targetUpdateRate = 0.3f;
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> target = nullptr;

public:
	FORCEINLINE FOnAttack& OnAttack()
	{
		return onAttack;
	}
	FORCEINLINE bool& GetCanAttack()
	{
		return canAttack;
	}
	FORCEINLINE TObjectPtr<AActor>& GetTarget()
	{
		return target;
	}
public:	
	// Sets default values for this component's properties
	UTD_AttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Attack();
	float IncreaseTime(const float& _current, const float& _max);

	void UpdateTarget();

public:
	void DrawDebug() override;
		
};
