// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

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