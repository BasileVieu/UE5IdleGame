#include "IdleHUD.h"
#include "Blueprint/UserWidget.h"
#include "IdleHUDWidget.h"

void AIdleHUD::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = GetOwningPlayerController();
	
	if (!PlayerController
		|| !PlayerController->IsLocalController())
	{
		return;
	}
	
	if (MainWidgetClass)
	{
		MainWidget = Cast<UIdleHUDWidget>(CreateWidget<UUserWidget>(PlayerController, MainWidgetClass));
		
		if (MainWidget)
		{
			MainWidget->AddToViewport();
		}
	}
}

void AIdleHUD::UpdateCashText(double Value) const
{
	MainWidget->UpdateResource(Value);
}