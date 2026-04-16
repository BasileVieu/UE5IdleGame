#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TierData.generated.h"

UENUM(BlueprintType)
enum class ETierDataType : uint8
{
	ParticleLifetime,
	ParticleCount,
	SpawnRate
};

UCLASS()
class IDLEGAME_API UTierData : public UDataAsset
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