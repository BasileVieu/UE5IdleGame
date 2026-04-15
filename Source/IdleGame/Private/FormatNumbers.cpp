#include "FormatNumbers.h"
#include "Math/UnrealMathUtility.h"

TMap<int, FString> FFormatNumbers::Units = {
	{0, ""},
	{1, "K"},
	{2, "M"},
	{3, "B"},
	{3, "T"}
};

int FFormatNumbers::CharA = 'a' - 0;

FString FFormatNumbers::Format(double Value)
{
	if (Value < 1)
	{
		return FString("0");
	}
	
	int32 n = FMath::FloorToInt(FMath::LogX(1000, Value));
	double m = Value / FMath::Pow(1000.0, n);
	
	FString Unit;
	
	if (n < Units.Num())
	{
		Unit = Units[n];
	}
	else
	{
		int UnitInt = n - Units.Num();
		int SecondUnit = UnitInt % 26;
		int FirstUnit = UnitInt / 26;
		
		TCHAR FirstUnitChar = static_cast<char>(FirstUnit + CharA);
		TCHAR SecondUnitChar = static_cast<char>(SecondUnit + CharA);
		
		Unit = FString(1, &FirstUnitChar) + FString(1, &SecondUnitChar);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("%f   %d   %f   %d   %s"), Value, n, m, Units.Num(), *Unit);
	
	return FString::SanitizeFloat(FMath::Floor(m * 100) / 100, 2) + Unit;
}