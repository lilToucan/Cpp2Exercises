#include "ObjectPoolingSettings.h"

static TAutoConsoleVariable<int> CvarDefaultPoolSize(TEXT("ObjectPooling.DefaultPoolSize"),50, TEXT("sets the default size of any added pool"),ECVF_Default);
void OnPoolSizeCvarChanged(IConsoleVariable* Var)
{
	float NewValue = Var->GetInt();
	UObjectPoolingSettings* Settings = UObjectPoolingSettings::Get();

	if (Settings->DefaultPoolSize == NewValue)
		return;

	Settings->DefaultPoolSize = NewValue;
	Settings->SaveConfig(CPF_Config, *Settings->GetDefaultConfigFilename());
}

UObjectPoolingSettings* UObjectPoolingSettings::Get()
{
	return GetMutableDefault<UObjectPoolingSettings>();
}

void UObjectPoolingSettings::PostInitProperties()
{
	Super::PostInitProperties();

	if (!IsTemplate())
		return;

	CvarDefaultPoolSize->Set(DefaultPoolSize, ECVF_SetByProjectSetting);
	CvarDefaultPoolSize.AsVariable()->SetOnChangedCallback(FConsoleVariableDelegate::CreateStatic(&OnPoolSizeCvarChanged));
}
