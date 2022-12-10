// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BL_FireTask.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_FireTask : public UBTTaskNode
{
	GENERATED_BODY()
	
//constructor
public:
	
	UBL_FireTask();
	

//c++ public methods
public:
	

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	

//>>>................................................................................................>>>//
	
};

