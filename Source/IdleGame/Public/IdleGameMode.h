#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "IdleGameMode.generated.h"

class AIdleHUD;
class UTiersManager;

UCLASS()
class IDLEGAME_API AIdleGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:	
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	AIdleHUD* IdleHUD;
	
	double Timer = 0.0;
	
	double Cash = 0;
	
	UPROPERTY(EditAnywhere)
	UTiersManager* TiersManager;
};