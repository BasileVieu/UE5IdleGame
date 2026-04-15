#include "IdleGameMode.h"
#include "IdleHUD.h"
#include "Kismet/GameplayStatics.h"

void AIdleGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	PrimaryActorTick.bCanEverTick = true;

	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		IdleHUD = Cast<AIdleHUD>(PlayerController->GetHUD());
	}
}

void AIdleGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	Cash += Cash < 10 ? 1 : Cash / 30;
	
	IdleHUD->UpdateCashText(Cash);
}