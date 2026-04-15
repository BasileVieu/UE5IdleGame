#include "IdleGame.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FIdleGameModule, IdleGame)void FIdleGameModule::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FIdleGameModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}