// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretActor.h"
#include "SpawnEnemy.h"
#include "TD_TurretProjectile.h"
#include "TD_MouvementComponent.h"
#include "Enemy.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ATurretActor::ATurretActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	mesh->SetupAttachment(RootComponent);

	spawnerComponent = CreateDefaultSubobject<USpawnComponent>("Spawner");
	AddInstanceComponent(spawnerComponent);


}

// Called when the game starts or when spawned
void ATurretActor::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

// Called every frame
void ATurretActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
	Action();
}

void ATurretActor::RemoveTarget()
{
	targets.Remove(target);
}

void ATurretActor::Init()
{
	if (targetClass)
	{
		TArray<AActor*> _actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), targetClass, _actors);
		for (AActor* _actor : _actors)
		{
			AEnemy* _enemy = Cast<AEnemy>(_actor);
			if (_enemy)
			{
				targets.Add(_enemy);
			}
		}
	}

	if (spawnerClass)
	{
		enemySpawner = Cast<ASpawnEnemy>(UGameplayStatics::GetActorOfClass(GetWorld(), spawnerClass));
		enemySpawner->GetSpawnComponent()->GetOnSpawn().AddDynamic(this, &ATurretActor::AddTarget);
	}
	
	spawnerComponent->GetOnSpawn().AddDynamic(this, &ATurretActor::Shoot);
}

void ATurretActor::DrawDebug()
{
	if (!useDebug) return;
	const UWorld* _world = GetWorld();
	const FVector& _location = GetActorLocation();
	DrawDebugSphere(_world, _location, range, 10, FColor::Red, false, -1, 0, 3);
}

void ATurretActor::Action()
{
	if (IsEnnemyInRange())
	{
		if (!canShoot || !target) return;
		spawnerComponent->Spawn();
		canShoot = false;
		FTimerHandle _timer;
		GetWorld()->GetTimerManager().SetTimer(_timer, this, &ATurretActor::ToogleShoot, fireRate, false);
	}
	
}

bool ATurretActor::IsEnnemyInRange()
{
	for (AEnemy* _enemy : targets)
	{
		if (_enemy)
		{
			float _distance = FVector::Dist(GetActorLocation(), _enemy->GetActorLocation());
			if (_distance <= range)
			{
				if (target != _enemy)
				{
					_enemy->GetMovement()->OnTrackFinish().AddDynamic(this, &ATurretActor::RemoveTarget);
					_enemy->GetLife()->OnDeath().AddDynamic(this, &ATurretActor::RemoveTarget);
				}
				target = _enemy;
				return true;
			}
		}
	}
	return false;
}

void ATurretActor::Shoot(AActor* _actor)
{
	if (!canShoot || !target)
	{
		_actor->Destroy();
		return;
	}

	ATD_TurretProjectile* _projectile = Cast<ATD_TurretProjectile>(_actor);
	if (_projectile)
	{
		_projectile->SetTarget(target);
	}
	
}

