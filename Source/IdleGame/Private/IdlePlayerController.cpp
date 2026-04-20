#include "IdlePlayerController.h"
#include "TiersSubsystem.h"
#include "UISubsystem.h"

void AIdlePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	GetGameInstance()->GetSubsystem<UUISubsystem>()->CreateHUDWidget(IdleHUDWidgetClass);
	GetGameInstance()->GetSubsystem<UTiersSubsystem>()->Init();
}