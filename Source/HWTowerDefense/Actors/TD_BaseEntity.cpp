// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_BaseEntity.h"

// Sets default values
ATD_BaseEntity::ATD_BaseEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATD_BaseEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD_BaseEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

