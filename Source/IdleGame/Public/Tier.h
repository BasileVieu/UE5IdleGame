#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Tier.generated.h"

class UTierData;

UCLASS()
class IDLEGAME_API UTier : public UDataAsset
{
	GENERATED_BODY()
	
public:
	void Init(FName NewTierName, double NewBaseProduction, double NewMultiplier);
	double GetProduction() const;	
	double GetMultiplier() const;
	void SetBaseProduction(double NewBaseProduction);
	void SetMultiplier(double NewMultiplier);
	
private:
	FName TierName;
	double BaseProduction = 1;
	double Multiplier = 1;
	
	UPROPERTY()
	TArray<UTierData*> TierDatas;
};