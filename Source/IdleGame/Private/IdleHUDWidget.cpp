#include "IdleHUDWidget.h"
#include "FormatNumbers.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "TiersSubsystem.h"

void UIdleHUDWidget::Init()
{
	GetGameInstance()->GetSubsystem<UTiersSubsystem>()->OnCashUpdated.AddUObject(this, &UIdleHUDWidget::UpdateCash);
}

void UIdleHUDWidget::AddTierDataWidget(UTierModifierDataAsset* InTierData)
{
	/*UTierModifierWidget* TierDataWidget = CreateWidget<UTierModifierWidget>(PlayerController, TierDataWidgetClass);
	
	TierDataWidget->Init(InTierData);
	
	TierDataWidgetsContainer->AddChild(TierDataWidget);*/
}

void UIdleHUDWidget::UpdateCash(double InValue) const
{
	if (CashText)
	{
		CashText->SetText(FText::FromString(FFormatNumbers::Format(InValue)));
	}
}