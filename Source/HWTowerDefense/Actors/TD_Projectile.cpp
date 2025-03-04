// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Projectile.h"
#include "TD_Enemy.h"

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
	OnActorBeginOverlap.AddDynamic(this, &ATD_Projectile::ManageOverlap);
}

// Called every frame
void ATD_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTo(DeltaTime);
}

void ATD_Projectile::MoveTo(const float& _delta)
{
	if (!target) return;
	const FVector& _loc = FMath::VInterpConstantTo(GetActorLocation(), target->GetActorLocation(), _delta, moveSpeed);
	SetActorLocation(_loc);
}

void ATD_Projectile::ManageOverlap(AActor* _this, AActor* _other)
{
	if(!_other) return;
	// On verifie que l'actor est le bon
	ATD_Enemy* _enemy = Cast<ATD_Enemy>(_other);
	if(!_enemy) return;
	// On inflige des degats
	_enemy->Destroy();
	Destroy();
}

void ATD_Projectile::TargetDestroyed(AActor* _this)
{
	Destroy();
}
