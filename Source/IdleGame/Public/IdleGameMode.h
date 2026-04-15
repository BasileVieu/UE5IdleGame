#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "IdleGameMode.generated.h"

class AIdleHUD;

UCLASS()
class IDLEGAME_API AIdleGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
private:
	UPROPERTY()
	AIdleHUD* IdleHUD;
	
	double Cash = 0;
};