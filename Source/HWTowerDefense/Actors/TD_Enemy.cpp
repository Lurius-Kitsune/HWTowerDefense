// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Enemy.h"

// Sets default values
ATD_Enemy::ATD_Enemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	movement = CreateDefaultSubobject<UTD_MovementComponent>("Movement");
	AddOwnedComponent(movement);
}

// Called when the game starts or when spawned
void ATD_Enemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

