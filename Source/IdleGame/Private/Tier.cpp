#include "Tier.h"

void UTier::Init(FName NewTierName, double NewBaseProduction, double NewMultiplier)
{
	TierName = NewTierName;
 	BaseProduction = NewBaseProduction;
 	Multiplier = NewMultiplier;
}

double UTier::GetProduction() const
{
	UE_LOG(LogTemp, Warning, TEXT("%s:   %f   %f"), *TierName.ToString(), BaseProduction * Multiplier, Multiplier);
	
	return BaseProduction * Multiplier;
}

double UTier::GetMultiplier() const
{
	return Multiplier;
}

void UTier::SetBaseProduction(const double NewBaseProduction)
{
	BaseProduction = NewBaseProduction;
}

void UTier::SetMultiplier(const double NewMultiplier)
{
	Multiplier = NewMultiplier;
}