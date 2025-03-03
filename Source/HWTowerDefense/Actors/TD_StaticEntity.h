#pragma once

#include "CoreMinimal.h"
#include "TD_BaseEntity.h"
#include "TD_StaticEntity.generated.h"

UCLASS()
class HWTOWERDEFENSE_API ATD_StaticEntity : public ATD_BaseEntity
{
    GENERATED_BODY()
protected:
    UPROPERTY(EditAnywhere, Category = "Entity|Components")
    TObjectPtr<UStaticMeshComponent> mesh = nullptr;

public:
    FORCEINLINE TObjectPtr<UStaticMeshComponent> GetMesh() const { return mesh; }

public:
    ATD_StaticEntity();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

};