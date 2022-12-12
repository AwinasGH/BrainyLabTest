// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/BL_RotateToBBEntry.h"

#include "AIController.h"

#include "BehaviorTree/BlackboardComponent.h"

#include "Kismet/KismetMathLibrary.h"

UBL_RotateToBBEntry::UBL_RotateToBBEntry()
{
	NodeName = "Rotate To BBEntry";
}

EBTNodeResult::Type UBL_RotateToBBEntry::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* LBlackBoard = OwnerComp.GetBlackboardComponent();
	if( !IsValid(LBlackBoard) ) return EBTNodeResult::Failed;

	APawn* LSelfCharacter = OwnerComp.GetAIOwner()->GetPawn();
	if( !IsValid(LSelfCharacter) ) return EBTNodeResult::Failed;

	const AActor* LBBEntryActor = Cast<AActor>(LBlackBoard->GetValueAsObject(BBEntry.SelectedKeyName));
	if( !IsValid(LBBEntryActor) ) return EBTNodeResult::Failed;

	FRotator LSelfRotator = LSelfCharacter->GetActorRotation();
	LSelfRotator.Yaw = UKismetMathLibrary::FindLookAtRotation(LSelfCharacter->GetActorLocation(), LBBEntryActor->GetActorLocation()).Yaw;

	LSelfCharacter->SetActorRotation(LSelfRotator);

	return EBTNodeResult::Succeeded;
}
