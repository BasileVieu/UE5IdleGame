#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UISubsystem.generated.h"

class UIdleHUDWidget;

UCLASS()
class IDLEGAME_API UUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void CreateHUDWidget(TSubclassOf<UIdleHUDWidget> InIdleHUDWidgetClass);
	
private:
	UPROPERTY()
	UIdleHUDWidget* IdleHUDWidget;
};