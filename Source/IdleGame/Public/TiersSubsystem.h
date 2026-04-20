#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TiersSubsystem.generated.h"

struct FTierInstance;
class UTiersDatabase;
class UTierDataAsset;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnTierEvent, FTierInstance&)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnCashUpdated, double)

UCLASS(Blueprintable)
class IDLEGAME_API UTiersSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void Init();
	void Update();
	void InitializeTiers();
	
	double GetCash() const;
	
	FOnTierEvent OnTierDisplayed;
	FOnCashUpdated OnCashUpdated;
	
private:
	void UpdateTiersFromIndex(int InIndex);
	double GetTierInstanceFinalProduction(const FTierInstance& InTierInstance);
	void SetTierInstanceMultiplier(FTierInstance& InTierInstance, double InValue);
	
	UPROPERTY()
	TArray<FTierInstance> TiersInstances;
	
	FTimerHandle UpdateTimerHandle;
	
	float Timer = 0.0f;
	
	double Cash = 0.0;
	
	int CurrentTierIndex = 0;
};