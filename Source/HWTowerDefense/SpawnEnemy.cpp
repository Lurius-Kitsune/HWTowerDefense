// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemy.h"
#include "Components/BillboardComponent.h"
#include "Enemy.h"
// Sets default values
ASpawnEnemy::ASpawnEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	icon->SetupAttachment(RootComponent);
	spawnComponent = CreateDefaultSubobject<USpawnComponent>("SpawnComponent");
	AddInstanceComponent(spawnComponent);

}

// Called when the game starts or when spawned
void ASpawnEnemy::BeginPlay()
{
	Super::BeginPlay();
	spawnComponent->GetOnSpawn().AddDynamic(this, &ASpawnEnemy::SetCheckpointsToEnemy);
}

// Called every frame
void ASpawnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnEnemy::SetCheckpointsToEnemy(AActor* _actor)
{
	if (AEnemy* _enemy = Cast<AEnemy>(_actor))
	{
		_enemy->GetMovement()->SetWaypoints(checkpoints);
	}
}

