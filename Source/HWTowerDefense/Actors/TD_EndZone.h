// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "TD_EndZone.generated.h"

class UBoxComponent;
UCLASS(Blueprintable)
class HWTOWERDEFENSE_API ATD_EndZone : public ATriggerVolume
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Trigger|Componnent")
	TObjectPtr<UBoxComponent> boxComponent = nullptr;
	UPROPERTY(EditAnywhere, Category = "EndZone|Debug")
	bool useDebug = true;
	
public:	
	// Sets default values for this actor's properties
	ATD_EndZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DrawTriggerZone();
	UFUNCTION() void OnEndZoneTriggered(AActor* _this, AActor* _other);

};
