// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_BaseComponent.h"
#include "TD_MouvementComponent.generated.h"

class ACheckpoint;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HWTOWERDEFENSE_API UTD_MovementComponent : public UTD_BaseComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Mouvement|Data")
	float moveSpeed = 200.0f;
	UPROPERTY(EditAnywhere, Category = "Mouvement|Data")
	float rotationSpeed = 200.0f;
	UPROPERTY(EditAnywhere, Category = "Mouvement|Data")
	TArray<FVector> path;

	UPROPERTY();
	int currentWaypointIndex = 0;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTrackFinish);
	UPROPERTY()
	FOnTrackFinish onTrackFinish;

public :
	FORCEINLINE void SetPath(const TArray<FVector>& _path)
	{
		path = _path;
		currentWaypointIndex = 0;
	}
	FORCEINLINE FOnTrackFinish& OnTrackFinish()
	{
		return onTrackFinish;
	}

public:	
	// Sets default values for this component's properties
	UTD_MovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void DrawDebug();

		
private:
	void MoveTo();
	void RotateTo();
	bool HasArrivedToWaypoint();

};
