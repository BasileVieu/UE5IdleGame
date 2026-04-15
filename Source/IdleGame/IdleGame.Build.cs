// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IdleGame : ModuleRules
{
	public IdleGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange([
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG"
		]);

		PrivateDependencyModuleNames.AddRange([]);
	}
}