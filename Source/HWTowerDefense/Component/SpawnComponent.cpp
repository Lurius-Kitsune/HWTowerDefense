// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnComponent.h"
#include "TD_BaseEntity.h"
#include "TD_MouvementComponent.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values for this component's properties
USpawnComponent::USpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void USpawnComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpawnComponent::Init()
{
	Super::Init();
	GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle, this, &USpawnComponent::Spawn, spawnRate, true);
}

void USpawnComponent::Spawn()
{
	if (!actorToSpawn || !canSpawn) return;
	ATD_BaseEntity* _spawned = owner->GetWorld()->SpawnActor<ATD_BaseEntity>(actorToSpawn, owner->GetActorLocation() + spawnLocation, owner->GetActorRotation());
	if(!_spawned) return;

	amountSpawner++;
	allSpawned.Add(_spawned);
	onSpawn.Broadcast(_spawned);
	UTD_MovementComponent* _movement = _spawned->FindComponentByClass<UTD_MovementComponent>();
	if (!_movement) return;
	_movement->SetPath(path);
}

void USpawnComponent::DrawDebug()
{
	Super::DrawDebug();
	const UWorld* _world = GetWorld();
	if (owner)
	{
		const FVector& _currentLoc = owner->GetActorLocation();
		DrawDebugBox(_world, _currentLoc + spawnLocation, FVector::OneVector * 100, FColor::Orange, false, -1, 0, 5.0f);
		if (path.Num() >= 1) DrawDebugLine(_world, _currentLoc, path[0], FColor::Orange, false, -1, 0, 5.0f);
	}
	
	if (path.Num() < 1) return;
	const int& _size = path.Num();
	for (int i = 0; i < _size ; i++)
	{
		const FVector& _point = path[i];
		DrawDebugSphere(_world, _point, 50, 8, FColor::Blue, false, -1.f, 0, 2.0f);
		if(i+1 < _size)
		{
			const FVector& _nextPoint = path[i + 1];
			DrawDebugLine(_world, _point, _nextPoint, FColor::Blue, false, -1.f, 0, 2.0f);
		}
	}
}

