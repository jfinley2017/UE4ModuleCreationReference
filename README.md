# UE4ModuleCreationReference
A small repo demonstrating the creation of a Editor module with a factory class for UE4. Factory classes are not included
in packaged games, they are only included in editor builds. This means we must make a new module (in this example, an editor-only module) to house our factory class or else our packaging will fail. 

The above repo is a minimal example of this and a walkthrough is provided below.

# Recreation Steps:
Substitute the following instances of MyGame/MinimalModule with your project naming convention.


1.) Edit your uproject to include the new module

  ![uproject-image](https://cdn.discordapp.com/attachments/381955162387906572/696983635018121226/unknown.png)
  
  - *Valid Types*: Runtime, RuntimeNoCommandlet, Developer, Editor, EditorNoCommandlet, Program
  - *Valid LoadingPhase Types*: EarliestPossible, PostConfigInit, PostSplashScreen, PreEarlyLoadingScreen, PreLoadingScreen, PreDefault, Default, PostDefault, PostEngineInit, None, Max
  
2.) If your new module is an editor module register it with ```MyGameEditor.Target.cs```, otherwise register it with ```MyGame.Target.cs```. These are located in ```Source/``` by default.

  ![Target.cs-Edits](https://cdn.discordapp.com/attachments/381955162387906572/696986391401463899/unknown.png)
  
3.) Create a new directory ```Source/MyNewModule``` for your new module.

  ![New-Directory](https://cdn.discordapp.com/attachments/381955162387906572/696988514021015552/unknown.png)
  
3.) Create (or duplicate ```MyGame.Build.cs```, located in ```Source/MyGame```) in the new directory. Name this 
the same as the module name you have chosen. In this example we would name the new build file ```MyNewModule.Build.cs```. Make the following changes.

  ![Module-build-cs](https://cdn.discordapp.com/attachments/381955162387906572/696990321686478918/unknown.png)
  
```c#
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
```  
4.) Create two new source files, ```MyNewModule.h``` and ```MyNewModule.cpp```. Place these in your new module directory and extend IModuleInterface as shown below.

```Source/MyNewModule/MyNewModule.h``` 

```c++
#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMinimalModuleEditor, Log, All);

class FMinimalModuleEditorModule : public IModuleInterface
{

public:

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

};
```

```Source/MyNewModule/MyNewModule.cpp```

```c++
#include "MinimalModule.h"

IMPLEMENT_GAME_MODULE(FMinimalModuleEditorModule, MinimalModuleEditor);

DEFINE_LOG_CATEGORY(LogMinimalModuleEditor);

#define LOCTEXT_NAMESPACE "FMinimalModuleEditor"

void FMinimalModuleEditorModule::StartupModule()
{
    UE_LOG(LogMinimalModuleEditor, Log, TEXT("MinimalModuleEditorStarted"));
}

void FMinimalModuleEditorModule::ShutdownModule()
{
    UE_LOG(LogMinimalModuleEditor, Log, TEXT("MinimalModuleEditorEnded"));

}

#undef LOCTEXT_NAMESPACE
```

5.) Fully clear intermediates and rebuild. 
