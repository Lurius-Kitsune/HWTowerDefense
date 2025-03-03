// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_MouvementComponent.h"
#include "Checkpoint.h"

// Sets default values for this component's properties
UTD_MouvementComponent::UTD_MouvementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UTD_MouvementComponent::BeginPlay()
{
	Super::BeginPlay();
	owner = GetOwner();
	SetNextWaypoint();
}


// Called every frame
void UTD_MouvementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToWaypoint();
}

void UTD_MouvementComponent::DrawDebug()
{
	if (!currentWaypoint || !owner) return;
	DrawDebugLine(GetWorld(), owner->GetActorLocation(), currentWaypoint->GetActorLocation(), FColor::Blue, false, -1, 0, 5.0f);
	DrawDebugBox(GetWorld(), currentWaypoint->GetActorLocation(), FVector(10.0f), FColor::Green, false, -1, 0, 5.0f);
}

void UTD_MouvementComponent::MoveToWaypoint()
{
	if (!currentWaypoint) return;

	FVector _location = FMath::VInterpConstantTo(owner->GetActorLocation(), currentWaypoint->GetActorLocation(), GetWorld()->GetDeltaSeconds(), movementSpeed);
	owner->SetActorLocation(_location);
	if (HasArrivedToWaypoint())
	{
		if (currentWaypointIndex == waypoints.Num() - 1)
		{
			onTrackFinish.Broadcast();
		}
		currentWaypointIndex++;
		SetNextWaypoint();
	}
}

void UTD_MouvementComponent::SetNextWaypoint()
{
	if (currentWaypointIndex >= waypoints.Num() || currentWaypointIndex < 0
		|| waypoints.Num() <= 0)
	{
		currentWaypoint = nullptr;
		return;
	}
	currentWaypoint = waypoints[currentWaypointIndex];
}

bool UTD_MouvementComponent::HasArrivedToWaypoint()
{
	if (!currentWaypoint) return true;

	return FVector::Dist(owner->GetActorLocation(), currentWaypoint->GetActorLocation()) <= 1.0f;
}

