// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Projectile.h"
#include "TD_Projectile.h"

// Sets default values
ATD_Projectile::ATD_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATD_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTo(DeltaTime);
}

void ATD_Projectile::MoveTo(const float& _delta)
{
	if(!target) return;
	const FVector& _loc = FMath::VInterpTo(GetActorLocation(), target->GetActorLocation(), _delta, moveSpeed);
}


