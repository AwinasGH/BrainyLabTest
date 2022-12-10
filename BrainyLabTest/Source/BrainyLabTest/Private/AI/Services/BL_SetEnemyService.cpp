// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/BL_SetEnemyService.h"

#include "BehaviorTree/BlackboardComponent.h"

#include "Character/AI/AIComponents/BL_AIPerceptionComponent.h"

#include "Character/AI/Controllers/BL_BaseAIController.h"


UBL_SetEnemyService::UBL_SetEnemyService()
{
	NodeName = "Set enemy";
}

void UBL_SetEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* LBlackBoard = OwnerComp.GetBlackboardComponent();
	
	ABL_BaseAIController* LController = Cast<ABL_BaseAIController>(OwnerComp.GetAIOwner());

	if( !IsValid(LBlackBoard) || !IsValid(LController) ) return;
	
	UBL_AIPerceptionComponent* LPerceptionComponent = Cast<UBL_AIPerceptionComponent>(LController->GetPerceptionComponent());
	if( !IsValid(LPerceptionComponent) ) return;
	
	AActor* LEnemy = LPerceptionComponent->GetClosestEnemy();
	LBlackBoard->SetValueAsObject(EnemyActor.SelectedKeyName, LEnemy);
}
