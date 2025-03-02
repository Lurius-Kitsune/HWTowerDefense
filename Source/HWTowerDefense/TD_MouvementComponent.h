// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TD_MouvementComponent.generated.h"

class ACheckpoint;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HWTOWERDEFENSE_API UTD_MouvementComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	AActor* owner;

	UPROPERTY(EditAnywhere, Category = "Mouvement|Data")
	float movementSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Mouvement|Data")
	TArray<TObjectPtr<ACheckpoint>> waypoints;

	UPROPERTY(VisibleAnywhere, Category = "Mouvement|Data")
	TObjectPtr<ACheckpoint> currentWaypoint;

	UPROPERTY();
	int currentWaypointIndex = 0;

public :
	FORCEINLINE void SetWaypoints(const TArray<TObjectPtr<ACheckpoint>>& _waypoints)
	{
		waypoints = _waypoints;
		SetNextWaypoint();
	}
public:	
	// Sets default values for this component's properties
	UTD_MouvementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void DrawDebug();

		
private:
	void MoveToWaypoint();
	void SetNextWaypoint();
	bool HasArrivedToWaypoint();

};
