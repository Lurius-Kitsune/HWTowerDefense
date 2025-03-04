// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Enemy.h"
#include "../TD_EnemyGISubsystem.h"
#include "TD_MouvementComponent.h"

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
	Init();
}

// Called every frame
void ATD_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATD_Enemy::Init()
{
	UTD_EnemyGISubsystem* _subsystem = GetGameInstance()->GetSubsystem<UTD_EnemyGISubsystem>();
	_subsystem->AddEnemy(this);
	OnDestroyed.AddDynamic(this, &ATD_Enemy::CustomDestroy);
	//OnActorHit.AddDynamic(this, &ATD_Enemy::CustomDestroy);
}

void ATD_Enemy::CustomDestroy(AActor* _this)
{
	UTD_EnemyGISubsystem* _subsystem = GetGameInstance()->GetSubsystem<UTD_EnemyGISubsystem>();
	if(!_subsystem) return;
	_subsystem->RemoveEnemy(this);

	if(!useDebug) return;
}

