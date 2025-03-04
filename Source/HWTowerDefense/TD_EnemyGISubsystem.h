// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TD_EnemyGISubsystem.generated.h"

/**
 * 
 */
class ATD_Enemy;
UCLASS()
class HWTOWERDEFENSE_API UTD_EnemyGISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UPROPERTY()
	TArray<TObjectPtr<ATD_Enemy>> allEnemies;

public:
	FORCEINLINE TArray<TObjectPtr<ATD_Enemy>> GetAllEnemies() const
	{
		return allEnemies;
	}
protected:
	virtual void Initialize(FSubsystemCollectionBase& _collection) override;
	virtual void Deinitialize() override;

public:
	void AddEnemy(const TObjectPtr<ATD_Enemy>& _toAdd);
	void RemoveEnemy(const TObjectPtr<ATD_Enemy>& _toRemove);
	TObjectPtr<ATD_Enemy> GetNearestEnemy(const TObjectPtr<AActor>& _caller, const float& _range);
};
