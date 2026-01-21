#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ObjectPoolingSettings.generated.h"

/**
 * 
 */
UCLASS(Config = ObjectPoolingSettings, defaultconfig, meta=(DisplayName = "ObjectPooling Defaults"))
class OBJECTPOOLING_API UObjectPoolingSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	public:
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Settings", meta = (ConsoleVariable = "ObjectPooling.DefaultPoolSize", ClampMin = 1))
	int DefaultPoolSize = 50;

	static UObjectPoolingSettings* Get();
	virtual void PostInitProperties() override;
};
