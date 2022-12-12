// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/BL_GenerateRandPointAroundActor.h"

#include "NavigationSystem.h"

#include "BehaviorTree/BlackboardComponent.h"


UBL_GenerateRandPointAroundActor::UBL_GenerateRandPointAroundActor()
{
	NodeName = "Generate Random Point Around BB Entry Actor";
}

void UBL_GenerateRandPointAroundActor::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* LBlackBoard = OwnerComp.GetBlackboardComponent();
	if( !IsValid(LBlackBoard) ) return;

	const AActor* LTargetActor = Cast<AActor>(LBlackBoard->GetValueAsObject(TargetActor.SelectedKeyName));
	if( !IsValid(LTargetActor) ) return;

	const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if( !IsValid(NavigationSystem) ) return;

	FNavLocation ResultLocation;

	if( NavigationSystem->GetRandomReachablePointInRadius(LTargetActor->GetActorLocation(), RandomRadius, ResultLocation) )
	{
		LBlackBoard->SetValueAsVector(RandomVectorAroundTarget.SelectedKeyName, ResultLocation.Location);
	}
}
