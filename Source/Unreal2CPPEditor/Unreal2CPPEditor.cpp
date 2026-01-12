// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal2CPPEditor.h"

#include "Unreal2CPP.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FIUnreal2CPPEditorModule, Unreal2CPPEditor, "Unreal2CPPEditor" );

DEFINE_LOG_CATEGORY(LogUnreal2CPP)

void FIUnreal2CPPEditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Unreal2CPPEditorModule StartupModule() called"));
}

void FIUnreal2CPPEditorModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Unreal2CPPEditorModule ShutdownModule() called"));
}

