// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BL_DangerDistanceCheckService.generated.h"

/*
 
*/
UCLASS()
class BRAINYLABTEST_API UBL_DangerDistanceCheckService : public UBTService
{
	GENERATED_BODY()


//constructor
public:
	
	UBL_DangerDistanceCheckService();

//c++ public methods
public:
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


//>>>................................................................................................>>>//


//Blueprint public values
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector DangerFlag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | Values")
		float Distance = 300.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector DangerActor;
};
