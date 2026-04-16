#include "IdleGameMode.h"
#include "IdleHUD.h"
#include "TiersManager.h"
#include "Kismet/GameplayStatics.h"

void AIdleGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	PrimaryActorTick.bCanEverTick = true;

	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		IdleHUD = Cast<AIdleHUD>(PlayerController->GetHUD());
	}
	
	TiersManager->Setup();
	
	TiersManager->Update();
}

void AIdleGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	Timer += DeltaSeconds;
	
	if (Timer >= 1.0)
	{
		Timer -= 1.0;
		
		TiersManager->Update();
	
		Cash += TiersManager->GetFinalProduction();
	
		IdleHUD->UpdateCashText(Cash);
	}
}