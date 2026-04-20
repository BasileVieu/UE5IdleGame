#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TierDataAsset.generated.h"

class UTierModifierDataAsset;

UCLASS()
class IDLEGAME_API UTierDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	void Init(FName InTierName, double InBaseProduction, double InMultiplier);
	double GetProduction() const;	
	double GetMultiplier() const;
	void SetBaseProduction(double InBaseProduction);
	void SetMultiplier(double InMultiplier);
	int GetTierDatasCount() const;
	UTierModifierDataAsset* GetTierData(int InIndex);
	
private:
	FName TierName;
	double BaseProduction = 1;
	double Multiplier = 1;
	
	UPROPERTY(EditAnywhere)
	TArray<UTierModifierDataAsset*> TierDatas;
};