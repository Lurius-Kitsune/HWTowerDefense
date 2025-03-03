#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TD_BaseComponent.generated.h"

class ATD_BaseEntity;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Abstract)
class HWTOWERDEFENSE_API UTD_BaseComponent : public UActorComponent
{
    GENERATED_BODY()
protected:
    UPROPERTY(VisibleAnywhere, Category = "Component|Owner")
    TObjectPtr<ATD_BaseEntity> owner = nullptr;

public:
    UTD_BaseComponent();

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual void Init();
    virtual void DrawDebug() {};

};