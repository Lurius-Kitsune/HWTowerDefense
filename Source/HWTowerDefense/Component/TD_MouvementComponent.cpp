// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_MouvementComponent.h"
#include "TD_BaseEntity.h"
#include "Checkpoint.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values for this component's properties
UTD_MovementComponent::UTD_MovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UTD_MovementComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTD_MovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveTo();
	RotateTo();
}

void UTD_MovementComponent::DrawDebug()
{
	if (!owner) return;
	DrawDebugLine(GetWorld(), owner->GetActorLocation(), path[currentWaypointIndex], FColor::Blue, false, -1, 0, 5.0f);
	DrawDebugBox(GetWorld(), path[currentWaypointIndex], FVector(10.0f), FColor::Green, false, -1, 0, 5.0f);
}

void UTD_MovementComponent::MoveTo()
{
	if(!owner || path.Num() < 1) return;
	FVector _location = FMath::VInterpConstantTo(owner->GetActorLocation(), path[currentWaypointIndex], GetWorld()->GetDeltaSeconds(), moveSpeed);
	owner->SetActorLocation(_location);
	if (HasArrivedToWaypoint())
	{
		if (currentWaypointIndex == path.Num() - 1)
		{
			onTrackFinish.Broadcast();
		}
		currentWaypointIndex++;
	}
}

void UTD_MovementComponent::RotateTo()
{
	if (!owner || path.Num() < 1) return;
	// Pour faire tourner vers une cible
	// Otenir la direction -> distance entre les 2
	const FVector& _currentLocation = owner->GetActorLocation();
	const FVector& _look = path[currentWaypointIndex] - _currentLocation;
	// Si on est déja dessus, on ne tourne plus
	if(_look == FVector::ZeroVector) return;
	// On cherche la rotation dans la lib kismet 
	// #include <Kismet/KismetMathLibrary.h>
	FRotator _rot = UKismetMathLibrary::FindLookAtRotation(_currentLocation, path[currentWaypointIndex]);
	// On le fait juste touner sur lui même
	_rot.Pitch = 0;
	_rot.Roll = 0;
	// On fait tourner l'acteur
	const FRotator& _newRot = FMath::RInterpConstantTo(owner->GetActorRotation(), _rot, GetWorld()->GetDeltaSeconds(), rotationSpeed);
	owner->SetActorRotation(_newRot);
}

bool UTD_MovementComponent::HasArrivedToWaypoint()
{
	return FVector::Dist(owner->GetActorLocation(), path[currentWaypointIndex]) <= 1.0f;
}

