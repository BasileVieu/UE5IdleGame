#pragma once

#include "CoreMinimal.h"
#include "Instances.generated.h"

class UTierModifierDataAsset;
class UTierDataAsset;

USTRUCT(Blueprintable)
struct FTierModifierInstance
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<UTierModifierDataAsset> TierModifierDataAsset;
};

USTRUCT(Blueprintable)
struct FTierInstance
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<UTierDataAsset> TierDataAsset;
	
	UPROPERTY()
	TArray<FTierModifierInstance> TierModifiersInstances;
	
	UPROPERTY()
	double BaseProduction = 1;
	
	UPROPERTY()
	double Multiplier = 1;
};