// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/BL_NewDodgeLocationService.h"

#include "NavigationSystem.h"

#include "BehaviorTree/BlackboardComponent.h"


UBL_NewDodgeLocationService::UBL_NewDodgeLocationService()
{
	NodeName = "Set Dodge Location";
}

void UBL_NewDodgeLocationService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* LBlackBoard = OwnerComp.GetBlackboardComponent();
	if( !IsValid(LBlackBoard) ) return;

	const AActor* LTargetActor = Cast<AActor>(LBlackBoard->GetValueAsObject(DodgingTarget.SelectedKeyName));
	if( !IsValid(LTargetActor) ) return;
	
	const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if( !IsValid(NavigationSystem) ) return;

	FNavLocation ResultLocation;

	const FVector LeftFromTargetLocation = LTargetActor->GetActorLocation() + (LTargetActor->GetActorRightVector() * -1) * Range;
	
	if( NavigationSystem->GetRandomReachablePointInRadius(LeftFromTargetLocation, RandomRadius, ResultLocation) )
	{
		LBlackBoard->SetValueAsVector(DodgeLocation.SelectedKeyName, ResultLocation.Location);

		return;
	}

	const FVector RightFromTargetLocation = LTargetActor->GetActorLocation() + LTargetActor->GetActorRightVector() * Range;
	
	if( NavigationSystem->GetRandomReachablePointInRadius(RightFromTargetLocation, RandomRadius, ResultLocation) )
	{
		LBlackBoard->SetValueAsVector(DodgeLocation.SelectedKeyName, ResultLocation.Location);

		return;
	}
	
	LBlackBoard->SetValueAsVector(DodgeLocation.SelectedKeyName, FVector::ZeroVector);
}
