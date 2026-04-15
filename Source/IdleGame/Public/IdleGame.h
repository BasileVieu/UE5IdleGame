#pragma once

#include "Modules/ModuleManager.h"

class FIdleGameModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
