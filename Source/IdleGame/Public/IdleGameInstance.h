#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "IdleGameInstance.generated.h"

class UTiersDatabase;

UCLASS()
class IDLEGAME_API UIdleGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UTiersDatabase* GetTiersDatabase() const { return TiersDatabase; }
	
private:	
	UPROPERTY(EditDefaultsOnly)
	UTiersDatabase* TiersDatabase;
};