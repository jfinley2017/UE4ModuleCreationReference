// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MinimalModuleEditor : ModuleRules
{
    public MinimalModuleEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UnrealEd" });
        PublicDependencyModuleNames.Add("MinimalModule");

        PublicIncludePaths.AddRange(new string[] { "MinimalModuleEditor/Public" } );
        PrivateIncludePaths.AddRange(new string[] { "MinimalModuleEditor/Private" } );

	}
}
