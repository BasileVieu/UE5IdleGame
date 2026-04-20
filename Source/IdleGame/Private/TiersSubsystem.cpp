#include "TiersSubsystem.h"
#include "IdleGameInstance.h"
#include "Instances.h"
#include "TierDataAsset.h"
#include "TiersDatabase.h"

void UTiersSubsystem::Init()
{
	InitializeTiers();
	
	GetWorld()->GetTimerManager().SetTimer(UpdateTimerHandle, this, &UTiersSubsystem::Update, 1.0f, true);
	
	OnTierDisplayed.Broadcast(TiersInstances[CurrentTierIndex]);
	
	OnCashUpdated.Broadcast(Cash);
}

void UTiersSubsystem::Update()
{
	SetTierInstanceMultiplier(TiersInstances[2], TiersInstances[2].Multiplier + 1);
	
	UpdateTiersFromIndex(0);
	
	Cash += GetTierInstanceFinalProduction(TiersInstances[0]);
	
	OnCashUpdated.Broadcast(Cash);
}

void UTiersSubsystem::InitializeTiers()
{
	UIdleGameInstance* IdleGameInstance = Cast<UIdleGameInstance>(GetGameInstance());
	
	int TierDataAssetsCount = IdleGameInstance->GetTiersDatabase()->GetTierDataAssets()->Num();
	
	for (int i = 0; i < TierDataAssetsCount; i++)
	{
		FTierInstance TierInstance;
		TierInstance.TierDataAsset = (*IdleGameInstance->GetTiersDatabase()->GetTierDataAssets())[i];
		
		int TierModifiersDataAssetsCount = TierInstance.TierDataAsset->GetTierDatasCount();
		
		for (int j = 0; j < TierModifiersDataAssetsCount; j++)
		{
			FTierModifierInstance TierModifierInstance;
			TierModifierInstance.TierModifierDataAsset = TierInstance.TierDataAsset->GetTierData(j);
			
			TierInstance.TierModifiersInstances.Add(TierModifierInstance);
		}
		
		TiersInstances.Add(TierInstance);
	}
}

double UTiersSubsystem::GetCash() const
{
	return Cash;
}

void UTiersSubsystem::UpdateTiersFromIndex(int InIndex)
{
	if (InIndex >= TiersInstances.Num())
	{
		return;
	}
	
	if (InIndex < TiersInstances.Num() - 1)
	{
		UpdateTiersFromIndex(InIndex + 1);
		
		SetTierInstanceMultiplier(TiersInstances[InIndex], 1.0 + GetTierInstanceFinalProduction(TiersInstances[InIndex + 1]) * 0.1);
	}
}

double UTiersSubsystem::GetTierInstanceFinalProduction(const FTierInstance& InTierInstance)
{
	return InTierInstance.BaseProduction * InTierInstance.Multiplier;
}

void UTiersSubsystem::SetTierInstanceMultiplier(FTierInstance& InTierInstance, const double InValue)
{
	InTierInstance.Multiplier = InValue;
}