// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BL_ObstacleCheck.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_ObstacleCheck : public UBTDecorator
{
	GENERATED_BODY()

	
//constructor
public:
	
	
	UBL_ObstacleCheck();
	

//c++ public methods
public:
	

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	

//>>>................................................................................................>>>//


//Blueprint public values
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector TargetActor;

	/*
		Muzzle socket name. The starting point of trace.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | Values")
		FName StartPointSocketName = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | Values")
		float SphereTraceRadius = 20.0f;
};
