#include "MinimalObjectFactory.h"
#include "AssetTypeCategories.h"
#include "MinimalFactoryObject.h"

UMinimalObjectFactory::UMinimalObjectFactory()
{
    bEditAfterNew = true;
    bCreateNew = true;
    SupportedClass = UMinimalFactoryObject::StaticClass();
}

uint32 UMinimalObjectFactory::GetMenuCategories() const
{
    return EAssetTypeCategories::Type::Misc;
}

UObject* UMinimalObjectFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    UMinimalFactoryObject* FactoryCreatedObject = NewObject<UMinimalFactoryObject>(InParent, InClass, InName, Flags);
    return FactoryCreatedObject;
}

FText UMinimalObjectFactory::GetDisplayName() const
{
    return FText::FromString("MinimalObjectFactoryObject");
}
