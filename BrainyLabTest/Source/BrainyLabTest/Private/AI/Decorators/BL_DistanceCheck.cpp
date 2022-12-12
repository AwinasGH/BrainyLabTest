// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Decorators/BL_DistanceCheck.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBL_DistanceCheck::UBL_DistanceCheck()
{
	NodeName = "In Distance";
}


bool UBL_DistanceCheck::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const UBlackboardComponent* LBlackboardComponent = OwnerComp.GetBlackboardComponent();
	if( !IsValid(LBlackboardComponent) ) return false;
	
	const AActor* LSelfActor = OwnerComp.GetAIOwner()->GetPawn();
	if( !IsValid(LSelfActor) ) return false;
	
	const AActor* LEnemyActor = Cast<AActor>(LBlackboardComponent->GetValueAsObject(TargetActor.SelectedKeyName));
	if( !IsValid(LEnemyActor) ) return false;

	return LSelfActor->GetDistanceTo(LEnemyActor) < Distance;
}
