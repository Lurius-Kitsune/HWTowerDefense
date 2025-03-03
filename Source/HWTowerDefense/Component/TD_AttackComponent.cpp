// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_AttackComponent.h"
#include "TD_Enemy.h"
#include "TD_Projectile.h"
#include "../TD_EnemyGISubsystem.h"

// Sets default values for this component's properties
UTD_AttackComponent::UTD_AttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTD_AttackComponent::BeginPlay()
{
	Super::BeginPlay();
	const UWorld* _world = GetWorld();
	enemySubsystem = _world->GetGameInstance()->GetSubsystem<UTD_EnemyGISubsystem>();
	FTimerHandle attackTimerHandle;
	_world->GetTimerManager().SetTimer(attackTimerHandle, this, &UTD_AttackComponent::UpdateTarget, targetUpdateRate, true, -1.f);
}


// Called every frame
void UTD_AttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (canAttack)
	{
		if(!target) return;
		Attack();

	}
	else
		currentTime = IncreaseTime(currentTime, fireRate);
}

void UTD_AttackComponent::Attack()
{
	if(!target) return;
	ATD_Projectile* _proj = GetWorld()->SpawnActor<ATD_Projectile>(projectileClass, owner->GetActorLocation(), owner->GetActorRotation());
	if(!_proj) return;
	_proj->SetTarget(target);
	canAttack = false;
}

float UTD_AttackComponent::IncreaseTime(const float& _current, const float& _max)
{
	float _time = _current + GetWorld()->DeltaTimeSeconds;
	if(_time >= _max)
	{
		_time = 0;
		canAttack = true;
	}
	return _time;
}

void UTD_AttackComponent::UpdateTarget()
{
	target = enemySubsystem->GetNearestEnemy(owner, range);
}

void UTD_AttackComponent::DrawDebug()
{
	Super::DrawDebug();
	const UWorld* _world = GetWorld();
	if (!owner) return;
	DrawDebugSphere(_world, owner->GetActorLocation(), range, 8, FColor::Red, false, -1.f, 0, 2.0f);
	if(!target) return;
	DrawDebugLine(_world, owner->GetActorLocation(), target->GetActorLocation(), FColor::Red, false, -1.f, 0, 2.0f);
}

