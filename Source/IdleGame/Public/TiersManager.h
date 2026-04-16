#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TiersManager.generated.h"

class UTier;

UCLASS()
class IDLEGAME_API UTiersManager : public UDataAsset
{
	GENERATED_BODY()
	
public:
	void Setup();
	void Update();
	double GetFinalProduction();
	
private:
	void UpdateTiersFromIndex(int index);
	
	UPROPERTY(EditAnywhere)
	TArray<UTier*> Tiers;
};