// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AI/Controllers/BL_BaseAIController.h"

#include "BehaviorTree/BehaviorTree.h"

#include "Character/AI/BL_AICharacter.h"

#include "Character/AI/AIComponents/BL_AIPerceptionComponent.h"


ABL_BaseAIController::ABL_BaseAIController()
{
	PrimaryActorTick.bCanEverTick = false;
	
	AIPerceptionComponent = CreateDefaultSubobject<UBL_AIPerceptionComponent>("AIPerceptionComponent");
	SetPerceptionComponent(*AIPerceptionComponent);
}


void ABL_BaseAIController::OnPossess(APawn* InPawn)
{
	if( !IsValid(InPawn) ) return;
	
	Super::OnPossess(InPawn);

	const ABL_AICharacter* AICharacter = Cast<ABL_AICharacter>(GetPawn());
	if( !IsValid(AICharacter) || !IsValid(AICharacter->BehaviorTree) ) return;

	RunBehaviorTree(AICharacter->BehaviorTree);
}
