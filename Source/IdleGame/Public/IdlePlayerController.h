#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IdlePlayerController.generated.h"

class UIdleHUDWidget;

UCLASS()
class IDLEGAME_API AIdlePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UIdleHUDWidget> IdleHUDWidgetClass;
	
	UPROPERTY()
	UIdleHUDWidget* IdleHUDWidget;
};