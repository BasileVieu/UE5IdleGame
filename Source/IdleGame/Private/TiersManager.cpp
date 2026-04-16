#include "TiersManager.h"
#include "Tier.h"

void UTiersManager::Setup()
{
	Tiers.Reset(0);
	
	UTier* TierA = NewObject<UTier>();
	TierA->Init("Tier A", 3.0, 1.0);
	Tiers.Add(TierA);
	
	UTier* TierB = NewObject<UTier>();
	TierB->Init("Tier B", 2.0, 2.0);
	Tiers.Add(TierB);
	
	UTier* TierC = NewObject<UTier>();
	TierC->Init("Tier C", 1.0, 3.0);
	Tiers.Add(TierC);
}

void UTiersManager::Update()
{
	Tiers[2]->SetMultiplier(Tiers[2]->GetMultiplier() + 1.0);
	
	UpdateTiersFromIndex(0);
}

double UTiersManager::GetFinalProduction()
{
	return Tiers[0]->GetProduction();
}

void UTiersManager::UpdateTiersFromIndex(int index)
{
	if (index >= Tiers.Num())
	{
		return;
	}
	
	if (index < Tiers.Num() - 1)
	{
		UpdateTiersFromIndex(index + 1);
		
		Tiers[index]->SetMultiplier(1.0 + Tiers[index + 1]->GetProduction() * 0.01);
	}
}