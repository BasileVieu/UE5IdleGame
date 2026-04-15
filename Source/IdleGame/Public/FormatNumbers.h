#pragma once

#include "CoreMinimal.h"

class IDLEGAME_API FFormatNumbers
{
public:
	static FString Format(double Value);
	
protected:
	static TMap<int, FString> Units;
	
	static int CharA;
};