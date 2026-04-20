#include "UISubsystem.h"

#include "IdleHUDWidget.h"
#include "IdlePlayerController.h"
#include "Blueprint/UserWidget.h"

void UUISubsystem::CreateHUDWidget(TSubclassOf<UIdleHUDWidget> InIdleHUDWidgetClass)
{
	AIdlePlayerController* IdlePlayerController = GetWorld()->GetFirstPlayerController<AIdlePlayerController>();
	
	IdleHUDWidget = CreateWidget<UIdleHUDWidget>(IdlePlayerController, InIdleHUDWidgetClass);
	IdleHUDWidget->AddToViewport();
	IdleHUDWidget->Init();
}