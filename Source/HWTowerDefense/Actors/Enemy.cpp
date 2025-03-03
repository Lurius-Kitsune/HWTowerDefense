// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	mesh->SetupAttachment(RootComponent);

	movement = CreateDefaultSubobject<UTD_MouvementComponent>("Movement");
	AddInstanceComponent(movement);

	life = CreateDefaultSubobject<UTD_LifeComponent>("Life");
	AddInstanceComponent(life);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	movement->OnTrackFinish().AddDynamic(this, &AEnemy::FinishedTrack);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
}

void AEnemy::DrawDebug()
{
	if (!useDebug) return;
	movement->DrawDebug();
}

void AEnemy::FinishedTrack()
{
	Destroy();
}

