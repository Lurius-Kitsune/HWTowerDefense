// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Tower.h"
#include "TD_AttackComponent.h"

// Sets default values
ATD_Tower::ATD_Tower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	attackComponent = CreateDefaultSubobject<UTD_AttackComponent>("AttackComponent");
	AddOwnedComponent(attackComponent);
}

// Called when the game starts or when spawned
void ATD_Tower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD_Tower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();

}

void ATD_Tower::DrawDebug()
{
	if (!useDebug) return;
	attackComponent->DrawDebug();
}

bool ATD_Tower::ShouldTickIfViewportsOnly() const
{
	return true;
}

