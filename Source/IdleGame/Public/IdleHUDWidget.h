#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "IdleHUDWidget.generated.h"

UCLASS()
class IDLEGAME_API UIdleHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION()
	void UpdateResource(double NewValue) const;
	
protected:
	UPROPERTY(VisibleAnywhere, meta=(BindWidget))
	UTextBlock* CashText;
};