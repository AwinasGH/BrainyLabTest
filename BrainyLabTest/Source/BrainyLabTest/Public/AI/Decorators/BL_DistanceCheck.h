// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/Decorators/BTDecorator_Blackboard.h"
#include "BL_DistanceCheck.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_DistanceCheck : public UBTDecorator
{
	GENERATED_BODY()
	

//constructor
public:
	
	
	UBL_DistanceCheck();
	

//c++ public methods
public:
	

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	

//>>>................................................................................................>>>//


//Blueprint public values
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | Values")
		float Distance = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector TargetActor;
};
