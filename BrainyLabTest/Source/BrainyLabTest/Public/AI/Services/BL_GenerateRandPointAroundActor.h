// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BL_GenerateRandPointAroundActor.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_GenerateRandPointAroundActor : public UBTService
{
	GENERATED_BODY()
	
//constructor
public:
	
	UBL_GenerateRandPointAroundActor();
	
	

//c++ public methods
public:
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


//>>>................................................................................................>>>//


//Blueprint public values
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector RandomVectorAroundTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardValue")
		float RandomRadius = 200.0f;
};
