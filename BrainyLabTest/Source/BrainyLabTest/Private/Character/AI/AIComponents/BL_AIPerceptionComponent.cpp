
#include "Character/AI/AIComponents/BL_AIPerceptionComponent.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Character/BL_BaseCharacter.h"
#include "Character/AI/Controllers/BL_BaseAIController.h"
#include "Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"
#include "Perception/AISenseConfig.h"
#include "Perception/AISenseConfig_Prediction.h"
#include "Perception/AISense_Prediction.h"

#include "Perception/AISense_Sight.h"


UBL_AIPerceptionComponent::UBL_AIPerceptionComponent(const FObjectInitializer& ObjectInitializer)
{
	
}

void UBL_AIPerceptionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnTargetPerceptionUpdated.AddDynamic(this, &UBL_AIPerceptionComponent::UBL_AIPerceptionComponent::OnPerceptionUpdated);
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
		if( !PerceiveActor->GetClass()->IsChildOf(ABL_BaseCharacter::StaticClass()) ) continue;
		
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

AActor* UBL_AIPerceptionComponent::GetClosestProjectile()
{
	TArray<AActor*> PerceiveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerceiveActors);
	if ( PerceiveActors.Num() == 0 )
	{
		if( CurrentProjectile != nullptr )
		{
			CurrentProjectile = nullptr;
		} 

		return nullptr;
	}
	
	const ABL_BaseAIController* AIController = Cast<ABL_BaseAIController>(GetOwner());
	if ( !IsValid(AIController) ) return nullptr;
	
	const APawn* AIPawn = AIController->GetPawn();
	if ( !IsValid(AIPawn) ) return nullptr;


	float BestDistance = MAX_FLT;
	AActor* ClosestProjectile = nullptr;
	
	
	for (const auto& PerceiveActor : PerceiveActors) 
	{
		if( !PerceiveActor->GetClass()->IsChildOf(ABL_BaseProjectile::StaticClass()) ) continue;
		
		const float CurrentDistance = (PerceiveActor->GetActorLocation() - AIPawn->GetActorLocation()).Size();
				
		if ( CurrentDistance < BestDistance )
		{
			BestDistance = CurrentDistance;
			ClosestProjectile = PerceiveActor;
		}
	}
	
	if( CurrentProjectile != ClosestProjectile && ClosestProjectile != nullptr )
	{
		CurrentProjectile = ClosestProjectile;
	}
	else if( CurrentProjectile != ClosestProjectile && CurrentProjectile != nullptr )
	{
		CurrentProjectile = nullptr;
	}

	return CurrentProjectile;
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

