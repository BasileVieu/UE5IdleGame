#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "IdleHUD.generated.h"

class UIdleHUDWidget;

UCLASS()
class IDLEGAME_API AIdleHUD : public AHUD
{
	GENERATED_BODY()
	
public:	
	void UpdateCashText(double Value) const;
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> MainWidgetClass;
	
private:
	UPROPERTY()
	UIdleHUDWidget* MainWidget;
};