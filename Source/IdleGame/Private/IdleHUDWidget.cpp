#include "IdleHUDWidget.h"
#include "FormatNumbers.h"
#include "Components/TextBlock.h"

void UIdleHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UIdleHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UIdleHUDWidget::UpdateResource(double Value) const
{
	if (CashText)
	{
		CashText->SetText(FText::FromString(FFormatNumbers::Format(Value)));
	}
}