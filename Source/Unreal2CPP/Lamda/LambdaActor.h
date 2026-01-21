#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LambdaActor.generated.h"

DECLARE_DELEGATE_OneParam(FOnTaskCompletedDelegate, bool bYay)
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnActionCompletedDelegate, int, FString)

USTRUCT(BlueprintType)
struct FWeatherData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	float MinTemp;
	UPROPERTY(EditAnywhere)
	float MaxTemp;
	UPROPERTY(EditAnywhere)
	float AverageTemp;

};

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
	UPROPERTY(VisibleAnywhere, Category="exercise||1")
	int PrimeNumbers;
	UFUNCTION(CallInEditor, Category="exercise||1")
	void AsyncFindPrimeNumbers();

	// exercise 2:
	UPROPERTY(VisibleAnywhere, Category="exercise||2")
	TArray<int> Inventory;
	UFUNCTION(CallInEditor, Category="exercise||2")
	void AsyncGenerateInventory();
	UFUNCTION(CallInEditor, Category="exercise||2")
	void AsyncSortInventory();

	// exercise 3:
	UPROPERTY(VisibleAnywhere, Category="exercise||3")
	int EnemiesNearOrigin = 0;
	UPROPERTY(VisibleAnywhere, Category="exercise||3")
	TArray<FVector> EnemiesPositions;
	UFUNCTION(CallInEditor, Category="exercise||3")
	void AsyncFindEnemies();

	// exercise 4:
	UPROPERTY(VisibleAnywhere, Category="exercise||4")
	FString Lore;
	UFUNCTION(CallInEditor, Category="exercise||4")
	void AsyncFillLore();

	// exercise 5:
	UPROPERTY(VisibleAnywhere, Category="exercise||5")
	FWeatherData WeatherData;
	UFUNCTION(CallInEditor, Category="exercise||5")
	void AsyncWeatherReportNotFromJojo();

protected:
	virtual void BeginPlay() override;
};
