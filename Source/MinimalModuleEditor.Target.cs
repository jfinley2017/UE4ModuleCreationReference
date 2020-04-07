// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class MinimalModuleEditorTarget : TargetRules
{
	public MinimalModuleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("MinimalModule");
        
        // Added
        ExtraModuleNames.Add("MinimalModuleEditor");
	}
}
