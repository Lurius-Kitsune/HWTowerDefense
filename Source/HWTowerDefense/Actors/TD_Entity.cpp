// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Entity.h"

// Sets default values
ATD_Entity::ATD_Entity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATD_Entity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD_Entity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

