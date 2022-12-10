
#include "Character/AI/AIComponents/BL_AIPerceptionComponent.h"

#include "Character/AI/Controllers/BL_BaseAIController.h"

#include "Perception/AISense_Sight.h"


UBL_AIPerceptionComponent::UBL_AIPerceptionComponent(const FObjectInitializer& ObjectInitializer)
{
	
}

AActor* UBL_AIPerceptionComponent::GetClosestEnemy()
{
	TArray<AActor*> PerceiveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerceiveActors);
	if ( PerceiveActors.Num() == 0 )
	{
		if( CurrentEnemy != nullptr )
		{
			CurrentEnemy = nullptr;
		} 

		return nullptr;
	}
	
	const ABL_BaseAIController* AIController = Cast<ABL_BaseAIController>(GetOwner());
	if ( !IsValid(AIController) ) return nullptr;
	
	const APawn* AIPawn = AIController->GetPawn();
	if ( !IsValid(AIPawn) ) return nullptr;


	float BestDistance = MAX_FLT;
	AActor* ClosestActor = nullptr;
	
	
	for (const auto& PerceiveActor : PerceiveActors) 
	{
		const float CurrentDistance = (PerceiveActor->GetActorLocation() - AIPawn->GetActorLocation()).Size();
				
		if ( CurrentDistance < BestDistance )
		{
			BestDistance = CurrentDistance;
			ClosestActor = PerceiveActor;
		}
	}

	
	if( CurrentEnemy != ClosestActor && ClosestActor != nullptr )
	{
		CurrentEnemy = ClosestActor;
	}
	else if( CurrentEnemy != ClosestActor && CurrentEnemy != nullptr )
	{
		CurrentEnemy = nullptr;
	}

	return CurrentEnemy;
}
