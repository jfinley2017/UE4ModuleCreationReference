// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MinimalFactoryObject.generated.h"

/**
 * 
 */
UCLASS()
class MINIMALMODULE_API UMinimalFactoryObject : public UObject
{
	GENERATED_BODY()
	
	
	UPROPERTY(EditDefaultsOnly, Category = "MinimalModuleFactoryObject")
	FName Name;


};
