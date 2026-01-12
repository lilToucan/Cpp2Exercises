#pragma once
// includes
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
// includes
#include "ObjectPoolSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInactiveObjectsChange, TSubclassOf<AActor>, ActorClass,float ,NumInactiveObjects);

UCLASS()
class OBJECTPOOLING_API UObjectPoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintType,BlueprintAssignable,BlueprintReadWrite, Category="Object Pool Subsystem")
	FInactiveObjectsChange OnInactivePoolingObjectsChanged;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Object Pool Subsystem")
	TMap<TSubclassOf<AActor>,FObjectPool> ObjectPoolMap;

	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	void AddPool(TSubclassOf<AActor> ActorClass, int32 initialSize = 1);

	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	TScriptInterface<IObjectPoolable> GetActor(TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	void ReturnActorToPool(TSubclassOf<AActor> ActorClass, TScriptInterface<IObjectPoolable> actorToReturn);
};
