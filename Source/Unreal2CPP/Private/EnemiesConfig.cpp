#include "EnemiesConfig.h"
#include "HAL/IConsoleManager.h"

static TAutoConsoleVariable<float> CvarEnemyGlobalHealthMult(TEXT("Enemy.GlobalHealthMult"),1.0f, TEXT("Health multiplier for enemies"),ECVF_Default);

static void OnHealthCvarChanged(IConsoleVariable* Var);

void OnHealthCvarChanged(IConsoleVariable* Var)
{
	float NewValue = Var->GetFloat();
	UEnemiesConfig* Settings = UEnemiesConfig::Get();

	if (Settings->GlobalHealthMult == NewValue)
		return;

	Settings->GlobalHealthMult = NewValue;
	Settings->SaveConfig(CPF_Config, *Settings->GetDefaultConfigFilename());
}

 UEnemiesConfig* UEnemiesConfig::Get()
{
	//return GetDefault<UEnemiesConfig>();
	return GetMutableDefault<UEnemiesConfig>();
}

void UEnemiesConfig::PostInitProperties()
{
	Super::PostInitProperties();

	if (!IsTemplate())
		return;

	CvarEnemyGlobalHealthMult->Set(GlobalHealthMult, ECVF_SetByProjectSetting);
	CvarEnemyGlobalHealthMult.AsVariable()->SetOnChangedCallback(FConsoleVariableDelegate::CreateStatic(&OnHealthCvarChanged));
}
