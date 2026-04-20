#include "TierDataAsset.h"

void UTierDataAsset::Init(FName InTierName, double InBaseProduction, double InMultiplier)
{
	TierName = InTierName;
 	BaseProduction = InBaseProduction;
 	Multiplier = InMultiplier;
}

double UTierDataAsset::GetProduction() const
{
	UE_LOG(LogTemp, Warning, TEXT("%s:   %f   %f"), *TierName.ToString(), BaseProduction * Multiplier, Multiplier);
	
	return BaseProduction * Multiplier;
}

double UTierDataAsset::GetMultiplier() const
{
	return Multiplier;
}

void UTierDataAsset::SetBaseProduction(const double InBaseProduction)
{
	BaseProduction = InBaseProduction;
}

void UTierDataAsset::SetMultiplier(const double InMultiplier)
{
	Multiplier = InMultiplier;
}

int UTierDataAsset::GetTierDatasCount() const
{
	return TierDatas.Num();
}

UTierModifierDataAsset* UTierDataAsset::GetTierData(int InIndex)
{
	return TierDatas[InIndex];
}