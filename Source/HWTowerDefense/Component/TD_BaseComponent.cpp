#include "TD_BaseComponent.h"
#include "TD_BaseEntity.h"

UTD_BaseComponent::UTD_BaseComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTD_BaseComponent::BeginPlay()
{
    Super::BeginPlay();
    Init();
}

void UTD_BaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTD_BaseComponent::Init()
{
    owner = Cast<ATD_BaseEntity>(GetOwner());
}