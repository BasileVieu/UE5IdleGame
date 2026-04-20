#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "IdleHUDWidget.generated.h"

class UTierModifierDataAsset;
class UTierModifierWidget;
class UScrollBox;

UCLASS()
class IDLEGAME_API UIdleHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Init();
	void AddTierDataWidget(UTierModifierDataAsset* InTierData);
	
	UFUNCTION()
	void UpdateCash(double InValue) const;
	
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UTierModifierWidget> TierDataWidgetClass;
	
	UPROPERTY(VisibleAnywhere, meta=(BindWidget))
	UScrollBox* TierDataWidgetsContainer;
	
	UPROPERTY(VisibleAnywhere, meta=(BindWidget))
	UTextBlock* CashText;
};