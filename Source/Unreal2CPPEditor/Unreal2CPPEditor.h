// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
// idk if i should remove or to change 
///** Main log category used across the project */
//DECLARE_LOG_CATEGORY_EXTERN(LogUnreal2CPP, Log, All);

class FIUnreal2CPPEditorModule : public IModuleInterface
{
public:
	// Begin IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	// End IModuleInterface implementation
};

