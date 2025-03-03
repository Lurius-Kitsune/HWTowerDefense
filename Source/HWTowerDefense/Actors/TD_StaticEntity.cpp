#include "TD_StaticEntity.h"
#include "TD_MouvementComponent.h"

ATD_StaticEntity::ATD_StaticEntity()
{
    PrimaryActorTick.bCanEverTick = true;
    RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
    mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    mesh->SetupAttachment(RootComponent);

}

void ATD_StaticEntity::BeginPlay()
{
    Super::BeginPlay();

}

void ATD_StaticEntity::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}