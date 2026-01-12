#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ObjectPoolable.generated.h"

UINTERFACE()
class UObjectPoolable : public UInterface
{
	GENERATED_BODY()
};

class OBJECTPOOLING_API IObjectPoolable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(ForceAsFunction), Category="Object Pool Subsystem")
	void BP_Activate();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(ForceAsFunction), Category="Object Pool Subsystem")
	void BP_Deactivate();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(ForceAsFunction), Category ="Object Pool Subsystem")
	void BP_UpdateTransform(FTransform GivenTransform, bool Sweep = true);
public:
};
