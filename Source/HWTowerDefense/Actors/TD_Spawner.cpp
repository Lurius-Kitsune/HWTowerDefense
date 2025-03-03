// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_Spawner.h"
#include "SpawnComponent.h"
#include "Components/BillboardComponent.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values
ATD_Spawner::ATD_Spawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	billbord = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	billbord->SetupAttachment(RootComponent);
	spawnComponent = CreateDefaultSubobject<USpawnComponent>(TEXT("SpawnComponent"));
	AddOwnedComponent(spawnComponent);
}

// Called when the game starts or when spawned
void ATD_Spawner::BeginPlay()
{
	Super::BeginPlay();
	DrawDebug();
}

// Called every frame
void ATD_Spawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
}

void ATD_Spawner::DrawDebug()
{
	if (!useDebug) return;
	if (spawnComponent) spawnComponent->DrawDebug();
}

bool ATD_Spawner::ShouldTickIfViewportsOnly() const
{
	return true;
}

