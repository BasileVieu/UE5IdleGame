#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TiersDatabase.generated.h"

class UTierDataAsset;

UCLASS()
class IDLEGAME_API UTiersDatabase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	TArray<UTierDataAsset*>* GetTierDataAssets() { return &TierDataAssets; }
	
private:
	UPROPERTY(EditAnywhere)
	TArray<UTierDataAsset*> TierDataAssets;
};