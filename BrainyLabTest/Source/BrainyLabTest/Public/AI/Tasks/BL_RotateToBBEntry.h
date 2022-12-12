// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BL_RotateToBBEntry.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_RotateToBBEntry : public UBTTaskNode
{
	GENERATED_BODY()
	
//constructor
public:
	
	UBL_RotateToBBEntry();
	

//c++ public methods
public:
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

//>>>................................................................................................>>>//


//Blueprint public values
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector BBEntry;
};
