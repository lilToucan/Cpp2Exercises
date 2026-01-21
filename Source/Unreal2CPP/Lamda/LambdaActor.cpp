#include "LambdaActor.h"
#include "Async/Async.h"

ALambdaActor::ALambdaActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALambdaActor::BeginPlay()
{
	Super::BeginPlay();
	//
	// OnTaskCompleted.BindLambda
	// (
	// 	[](bool bSucces)
	// 	{
	// 		if (bSucces)
	// 		{
	// 			UE_LOG(LogTemp, Warning, TEXT("Success"));
	// 		}
	// 		else
	// 			UE_LOG(LogTemp, Warning, TEXT("Failure"));
	// 	}
	// );
	//
	// /* used to avoid reference cycle and null pointer when an actor is destroyed
	// // OnTaskCompleted.BindWeakLambda
	// // (
	// // 	this,
	// // 	[this](bool bSucces)
	// // 	{
	// // 		if (bSucces)
	// // 		{
	// // 			UE_LOG(LogTemp, Warning, TEXT("Success AAAAAAAAAA"));
	// // 		}
	// // 		else
	// // 			UE_LOG(LogTemp, Warning, TEXT("Failure AAAAAAAAAAAA"));
	// // 	}
	// // );
	// */
	//
	// OnActionCompleted.AddLambda
	// (
	// 	[](int num, FString string)
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("%s N°1"), *string);
	// 	}
	// );
	// OnActionCompleted.AddLambda
	// (
	// 	[](int num, FString string)
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("%s N°2"), *string);
	// 	}
	// );
	//
	//
	// if (GetWorld())
	// {
	// 	GetWorld()->GetTimerManager().SetTimer
	// 	(
	// 		TimerHandle,
	// 		[this]()
	// 		{
	// 			ExecuteTask();
	// 		},
	// 		2.0f,
	// 		false
	// 	);
	// }
}

void ALambdaActor::ExecuteTask()
{
	// if (OnTaskCompleted.IsBound())
	// 	OnTaskCompleted.Execute(true);
	//
	// if (OnActionCompleted.IsBound())
	// 	OnActionCompleted.Broadcast(42, TEXT("Hello World"));

	AsyncHeavyCalculation();
}

void ALambdaActor::AsyncHeavyCalculation()
{
	Async(EAsyncExecution::Thread,
	      [this]()
	      {
		      int iterationNum = 0;
		      for (int i = 0; i < Iterations; i++)
		      {
			      iterationNum += i;
		      }
		      UE_LOG(LogTemp, Log, TEXT("iterationNum = %d"), iterationNum);

		      // Async(EAsyncExecution::TaskGraph,[this, iterationNum]()
		      // 	{
		      // 		this->Result = iterationNum;
		      // 	}
		      // );
	      }
	);
}

void ALambdaActor::HeavyCalculation()
{
	int iterationNum = 0;
	for (int i = 0; i < Iterations; i++)
	{
		iterationNum += i;
	}
	UE_LOG(LogTemp, Log, TEXT("iterationNum = %d"), iterationNum);
}


// Exercise start:
void ALambdaActor::AsyncFindPrimeNumbers()
{
	Async(EAsyncExecution::Thread,
	      [this]()
	      {
		      for (int i = 2; i <= 200000; i++) // skip 1 cause it's not prime
		      {
			      bool isPrime = true;
			      for (int j = 2; j < i; j++)
			      //(|ex i = 4 & j = 2,3  the  i%2 == 0 therefore not prime| | i = 7 j= 2,3,4,5,6 I%J != 0 |)
			      {
				      if (i % j == 0)
					      isPrime = false;
			      }

			      if (isPrime)
				      PrimeNumbers++;
		      }
	      }
	);
}

void ALambdaActor::AsyncGenerateInventory()
{
	Async(EAsyncExecution::Thread,
	      [this]()
	      {
		      TArray<int> array;
		      for (int i = 0; i < 100000; i++)
		      {
			      float d = i;
			      int ID = i * FMath::Cos(d);
			      array.Add(ID);
		      }
		      AsyncTask(ENamedThreads::GameThread, [this, MillionArray = MoveTemp(array)]() mutable
		                {
			                Swap(this->Inventory, MillionArray);

			                Async(EAsyncExecution::ThreadPool, [this, ArrayToDie = MoveTemp(MillionArray)]()
			                {
			                });
		                }
		      );
	      }
	);
}

void ALambdaActor::AsyncSortInventory()
{
	AsyncThread([this]() { Inventory.Sort(); });
}
