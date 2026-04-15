using UnrealBuildTool;

public class IdleGameTarget : TargetRules
{
    public IdleGameTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("IdleGame");
    }
}