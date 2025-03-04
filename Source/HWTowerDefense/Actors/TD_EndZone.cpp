// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_EndZone.h"
#include "TD_Enemy.h"
#include "Components/BoxComponent.h"

// Sets default values
ATD_EndZone::ATD_EndZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	boxComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATD_EndZone::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ATD_EndZone::OnEndZoneTriggered);
}

// Called every frame
void ATD_EndZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawTriggerZone();
}

void ATD_EndZone::DrawTriggerZone()
{
	if(!useDebug) return;
	const FVector& _size = boxComponent->GetCollisionShape().GetExtent();
	DrawDebugBox(GetWorld(), GetActorLocation(), _size, FColor::Green, true, -1, 0, 2.5f);
}

void ATD_EndZone::OnEndZoneTriggered(AActor* _this, AActor* _other)
{
	if (!_other) return;
	// On verifie que l'actor est le bon
	ATD_Enemy* _enemy = Cast<ATD_Enemy>(_other);
	if (!_enemy) return;
	// On inflige des degats
	_enemy->Destroy();
}

