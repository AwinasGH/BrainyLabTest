// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/BL_DangerDistanceCheckService.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBL_DangerDistanceCheckService::UBL_DangerDistanceCheckService()
{
	NodeName = "Danger In Distance Check";
}

void UBL_DangerDistanceCheckService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* LBlackBoard = OwnerComp.GetBlackboardComponent();
	if( !IsValid(LBlackBoard) ) return;

	const AActor* LSelfActor = OwnerComp.GetAIOwner()->GetPawn();
	if( !IsValid(LSelfActor) ) return;
	
	const AActor* LDangerActor = Cast<AActor>(LBlackBoard->GetValueAsObject(DangerActor.SelectedKeyName));
	if( !IsValid(LDangerActor) )
	{
		LBlackBoard->SetValueAsBool(DangerFlag.SelectedKeyName, false);

		return;
	}

	LBlackBoard->SetValueAsBool(DangerFlag.SelectedKeyName, LSelfActor->GetDistanceTo(LDangerActor) < Distance);
}
