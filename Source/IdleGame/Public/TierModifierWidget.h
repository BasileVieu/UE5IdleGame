#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TierModifierWidget.generated.h"

class UTierModifierDataAsset;

UCLASS()
class IDLEGAME_API UTierModifierWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Init(UTierModifierDataAsset* InTierData);
};