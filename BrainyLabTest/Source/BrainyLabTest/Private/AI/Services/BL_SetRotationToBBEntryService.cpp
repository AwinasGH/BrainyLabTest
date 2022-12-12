// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/BL_SetRotationToBBEntryService.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"


UBL_SetRotationToBBEntryService::UBL_SetRotationToBBEntryService()
{
	NodeName = "Set Rotation To BB Entry Service";
}

void UBL_SetRotationToBBEntryService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const UBlackboardComponent* LBlackBoard = OwnerComp.GetBlackboardComponent();
	if( !IsValid(LBlackBoard) ) return;

	APawn* LSelfCharacter = OwnerComp.GetAIOwner()->GetPawn();
	if( !IsValid(LSelfCharacter) ) return;

	const AActor* LBBEntryActor = Cast<AActor>(LBlackBoard->GetValueAsObject(BBEntry.SelectedKeyName));
	if( !IsValid(LBBEntryActor) ) return;

	FRotator LSelfRotator = LSelfCharacter->GetActorRotation();
	LSelfRotator.Yaw = UKismetMathLibrary::FindLookAtRotation(LSelfCharacter->GetActorLocation(), LBBEntryActor->GetActorLocation()).Yaw;

	LSelfCharacter->SetActorRotation(LSelfRotator);
}
