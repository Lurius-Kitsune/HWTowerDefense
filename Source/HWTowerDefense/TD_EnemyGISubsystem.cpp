// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_EnemyGISubsystem.h"
#include "TD_Enemy.h"
#include <Kismet/KismetSystemLibrary.h>

void UTD_EnemyGISubsystem::Initialize(FSubsystemCollectionBase& _collection)
{
	Super::Initialize(_collection);
}

void UTD_EnemyGISubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UTD_EnemyGISubsystem::AddEnemy(const TObjectPtr<ATD_Enemy>& _toAdd)
{
	if(!_toAdd || allEnemies.Contains(_toAdd)) return;
	allEnemies.Add(_toAdd);
}

void UTD_EnemyGISubsystem::RemoveEnemy(const TObjectPtr<ATD_Enemy>& _toRemove)
{
	if(!allEnemies.Contains(_toRemove)) return;
	allEnemies.Remove(_toRemove);
}

TObjectPtr<ATD_Enemy> UTD_EnemyGISubsystem::GetNearestEnemy(const TObjectPtr<AActor>& _caller, const float& _range)
{
	const int& _size = allEnemies.Num();
	float _dist = _range;
	ATD_Enemy* _nearest = nullptr;
	for (int _i = 0; _i < _size; _i++)
	{
		ATD_Enemy* _enemy = allEnemies[_i];
		if(!_enemy) continue;
		const float& _newDist = FVector::Dist(_caller->GetActorLocation(), _enemy->GetActorLocation());
		if (_newDist < _dist)
		{
			_dist = _newDist;
			_nearest = _enemy;
		}
	}

	return _nearest;
}
