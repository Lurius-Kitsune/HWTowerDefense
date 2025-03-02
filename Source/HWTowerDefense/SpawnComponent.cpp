// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnComponent.h"

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
	owner = GetOwner();
	GetWorld()->GetTimerManager().SetTimer(spawnTimer, this, &USpawnComponent::Spawn, spawnRate, true);
}


// Called every frame
void USpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpawnComponent::Spawn()
{
	if (actorToSpawn)
	{
		AActor* _actor = owner->GetWorld()->SpawnActor<AActor>(actorToSpawn, owner->GetActorLocation(), owner->GetActorRotation());
		OnSpawn.Broadcast(_actor);
	}
}

