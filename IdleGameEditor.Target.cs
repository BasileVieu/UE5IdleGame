using UnrealBuildTool;

public class IdleGameEditorTarget : TargetRules
{
    public IdleGameEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        ExtraModuleNames.Add("IdleGame");  // module runtime
        ExtraModuleNames.Add("IdleGameEditor"); // module editor
    }
}