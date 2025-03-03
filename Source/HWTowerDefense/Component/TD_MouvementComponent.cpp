// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_MouvementComponent.h"
#include "TD_BaseEntity.h"
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
}


// Called every frame
void UTD_MouvementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTD_MouvementComponent::DrawDebug()
{
	if (!owner) return;
	DrawDebugLine(GetWorld(), owner->GetActorLocation(), waypoints[currentWaypointIndex], FColor::Blue, false, -1, 0, 5.0f);
	DrawDebugBox(GetWorld(), waypoints[currentWaypointIndex], FVector(10.0f), FColor::Green, false, -1, 0, 5.0f);
}

void UTD_MouvementComponent::MoveTo()
{
	if(!owner || waypoints.Num() < 1) return;
	FVector _location = FMath::VInterpConstantTo(owner->GetActorLocation(), waypoints[currentWaypointIndex], GetWorld()->GetDeltaSeconds(), moveSpeed);
	owner->SetActorLocation(_location);
	if (HasArrivedToWaypoint())
	{
		if (currentWaypointIndex == waypoints.Num() - 1)
		{
			onTrackFinish.Broadcast();
		}
		currentWaypointIndex++;
	}
}

void UTD_MouvementComponent::RotateTo()
{
}

bool UTD_MouvementComponent::HasArrivedToWaypoint()
{
	return FVector::Dist(owner->GetActorLocation(), waypoints[currentWaypointIndex]) <= 1.0f;
}

