// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_TurretProjectile.h"

// Sets default values
ATD_TurretProjectile::ATD_TurretProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	mesh->SetupAttachment(RootComponent);

	movement = CreateDefaultSubobject<UTD_MouvementComponent>("Movement");
	AddInstanceComponent(movement);

}

// Called when the game starts or when spawned
void ATD_TurretProjectile::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

// Called every frame
void ATD_TurretProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();

}

void ATD_TurretProjectile::HitTarget()
{
	target->GetLife()->RemoveLifePoints(damage);
	target = nullptr;
	Destroy();
}

void ATD_TurretProjectile::MissTarget()
{
	target = nullptr;
	Destroy();
}

void ATD_TurretProjectile::Init()
{
	movement->OnTrackFinish().AddDynamic(this, &ATD_TurretProjectile::HitTarget);
}

void ATD_TurretProjectile::DrawDebug()
{
	if (!useDebug) return;
	movement->DrawDebug();
}

