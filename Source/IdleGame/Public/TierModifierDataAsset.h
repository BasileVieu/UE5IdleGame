#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TierModifierDataAsset.generated.h"

UENUM(BlueprintType)
enum class ETierDataType : uint8
{
	ParticleLifetime,
	ParticleCount,
	SpawnRate,
	Velocity
};

UCLASS()
class IDLEGAME_API UTierModifierDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	ETierDataType TierDataType;
	
	UPROPERTY(EditAnywhere)
	double BaseValue;
	
	UPROPERTY(EditAnywhere)
	double BaseCost;
};