// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Decorators/BL_ObstacleCheck.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"

UBL_ObstacleCheck::UBL_ObstacleCheck()
{
	
}

bool UBL_ObstacleCheck::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const UBlackboardComponent* LBlackboardComponent = OwnerComp.GetBlackboardComponent();
	if( !IsValid(LBlackboardComponent) ) return false;
	
	ACharacter* LSelfCharacter = Cast<ACharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if( !IsValid(LSelfCharacter) ) return false;
	
	const AActor* LTargetActor = Cast<AActor>(LBlackboardComponent->GetValueAsObject(TargetActor.SelectedKeyName));
	if( !IsValid(LTargetActor) ) return false;

	const FVector StartLocation = LSelfCharacter->GetMesh()->GetSocketLocation(StartPointSocketName);
	
	FHitResult OutHit;
	
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(LSelfCharacter);
	
	UKismetSystemLibrary::SphereTraceSingle(
											GetWorld(),
											StartLocation,
											LTargetActor->GetActorLocation(),
											SphereTraceRadius,
											TraceTypeQuery1,
											false,
											ActorsToIgnore,
											EDrawDebugTrace::None, OutHit, true);
	
	return OutHit.GetActor() != LTargetActor;
}
