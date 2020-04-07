// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MinimalModule : ModuleRules
{
    public MinimalModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

        PublicIncludePaths.AddRange(new string[] { "MinimalModule/Public" } );
        PrivateIncludePaths.AddRange(new string[] { "MinimalModule/Private" } );

	}
}
