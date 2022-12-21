
#include "Character/AI/AIComponents/BL_AIPerceptionComponent.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Character/AI/Controllers/BL_BaseAIController.h"

#include "Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"

#include "Perception/AISenseConfig_Prediction.h"
#include "Perception/AISense_Prediction.h"
#include "Perception/AISense_Sight.h"

#include "Character/BL_BaseCharacter.h"



UBL_AIPerceptionComponent::UBL_AIPerceptionComponent(const FObjectInitializer& ObjectInitializer)
{
	
}

void UBL_AIPerceptionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnTargetPerceptionUpdated.AddDynamic(this, &UBL_AIPerceptionComponent::UBL_AIPerceptionComponent::OnPerceptionUpdated);
}



template <typename SenseType, typename ClassSearch>
AActor* UBL_AIPerceptionComponent::GetClosestPerceiver(AActor* ChachedVariable)
{
	TArray<AActor*> PerceiveActors;
	GetCurrentlyPerceivedActors(SenseType::StaticClass(), PerceiveActors);
	if ( PerceiveActors.Num() == 0 )
	{
		if( ChachedVariable != nullptr )
		{
			ChachedVariable = nullptr;
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
		if( !PerceiveActor->GetClass()->IsChildOf(ClassSearch::StaticClass()) ) continue;
		
		const float CurrentDistance = (PerceiveActor->GetActorLocation() - AIPawn->GetActorLocation()).Size();
				
		if ( CurrentDistance < BestDistance )
		{
			BestDistance = CurrentDistance;
			ClosestActor = PerceiveActor;
		}
	}

	if( ChachedVariable != ClosestActor && ClosestActor != nullptr )
	{
		ChachedVariable = ClosestActor;
	}
	else if( ChachedVariable != ClosestActor && ChachedVariable != nullptr )
	{
		ChachedVariable = nullptr;
	}

	return ChachedVariable;
}



void UBL_AIPerceptionComponent::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	const UBlackboardComponent* LBlackboardComp = UAIBlueprintHelperLibrary::GetBlackboard(GetOwner());
	if( !IsValid(LBlackboardComp) ) return;
	
	AActor* LEnemyActor = Cast<AActor>(LBlackboardComp->GetValueAsObject(EnemyActorKeyName));
	if( !IsValid(LEnemyActor) ) return;
	
	ABL_BaseAIController* LOwnerController = Cast<ABL_BaseAIController>(GetOwner());
	if( !IsValid(LOwnerController) ) return;
	
	for( const auto& SenseConfig : SensesConfig )
	{
		if( const UAISenseConfig_Prediction* PredictionConfig = Cast<UAISenseConfig_Prediction>(SenseConfig.Get()) )
		{
			UAISense_Prediction::RequestControllerPredictionEvent(LOwnerController, LEnemyActor, PredictionTime);
			
			break;
		}
	}
}

