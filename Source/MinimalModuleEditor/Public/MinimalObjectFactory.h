#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MinimalObjectFactory.generated.h"

/**
 * Minimal factory class. 
 * Allows for UMinimalObjects to show in the editor content browser context clicks.
 * Cannot be used in Game modules as it will cause problems with building.
 */
UCLASS()
class MINIMALMODULEEDITOR_API UMinimalObjectFactory : public UFactory
{
    GENERATED_BODY()

    public:

    UMinimalObjectFactory();

    // UFactory
    virtual FText GetDisplayName() const override;
    virtual uint32 GetMenuCategories() const override;
    virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
    // ~UFactory


};
