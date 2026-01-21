#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EnemiesConfig.generated.h"

/**
 * Config: EnemySettings
 * Project -> Config/DefaultEnemySettings.ini
 * User/Build -> Saved/Config/EnemySettings.ini
 */
UCLASS(Config = EnemiesSettings, defaultconfig, meta=(DisplayName = "Enemies Configuration"))
class UNREAL2CPP_API UEnemiesConfig : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Assets", meta =(AllowedClasses ="DataTable"))
	TSoftObjectPtr<UDataTable> EnemyDataTable;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Balancing", meta = (ConsoleVariable = "Enemy.GloabalHealthMult", ClampMin = 0.1f))
	float GlobalHealthMult = 1;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category="Debug", meta=(ConsoleVariable ="Enemy.DebugEnemyInfo"))
	bool bDebugEnemyInfo = false;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UEnemiesConfig* Get();

	virtual void PostInitProperties() override;
};
