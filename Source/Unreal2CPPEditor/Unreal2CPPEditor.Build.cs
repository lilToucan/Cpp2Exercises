// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Unreal2CPPEditor : ModuleRules
{
    public Unreal2CPPEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "AIModule",
            "StateTreeModule",
            "GameplayStateTreeModule",
            "UMG",
            "Slate"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { "Unreal2CPP", "UnrealEd", "Slate", "SlateCore" });

        PublicIncludePaths.AddRange(new string[] {
            "Unreal2CPP",
            "Unreal2CPP/Variant_Platforming",
            "Unreal2CPP/Variant_Platforming/Animation",
            "Unreal2CPP/Variant_Combat",
            "Unreal2CPP/Variant_Combat/AI",
            "Unreal2CPP/Variant_Combat/Animation",
            "Unreal2CPP/Variant_Combat/Gameplay",
            "Unreal2CPP/Variant_Combat/Interfaces",
            "Unreal2CPP/Variant_Combat/UI",
            "Unreal2CPP/Variant_SideScrolling",
            "Unreal2CPP/Variant_SideScrolling/AI",
            "Unreal2CPP/Variant_SideScrolling/Gameplay",
            "Unreal2CPP/Variant_SideScrolling/Interfaces",
            "Unreal2CPP/Variant_SideScrolling/UI"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
