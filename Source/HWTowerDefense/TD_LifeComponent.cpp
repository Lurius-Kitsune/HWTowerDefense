// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_LifeComponent.h"

// Sets default values for this component's properties
UTD_LifeComponent::UTD_LifeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTD_LifeComponent::BeginPlay()
{
	Super::BeginPlay();
	owner = GetOwner();
	// ...
	
}


// Called every frame
void UTD_LifeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTD_LifeComponent::Death()
{
	onDeath.Broadcast();
	owner->Destroy();
}

