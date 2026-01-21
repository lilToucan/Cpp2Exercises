#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LambdaActor.generated.h"

DECLARE_DELEGATE_OneParam(FOnTaskCompletedDelegate, bool bYay)
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnActionCompletedDelegate, int , FString)

UCLASS()
class UNREAL2CPP_API ALambdaActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Result = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Iterations = 1000000;
	
	FOnTaskCompletedDelegate OnTaskCompleted;
	FOnActionCompletedDelegate OnActionCompleted;
	FTimerHandle TimerHandle;

	ALambdaActor();
	void ExecuteTask();
	
	void AsyncHeavyCalculation();
	void HeavyCalculation();

	// exercise 1:
	UPROPERTY(VisibleAnywhere)
	int PrimeNumbers;
	UFUNCTION(CallInEditor)
	void AsyncFindPrimeNumbers();

	// exercise 2:
	UPROPERTY(EditAnywhere)
	TArray<int> Inventory;
	UFUNCTION(CallInEditor)
	void AsyncGenerateInventory();
	UFUNCTION(CallInEditor)
	void AsyncSortInventory();

protected:
	virtual void BeginPlay() override;
};
