// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BL_NewDodgeLocationService.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_NewDodgeLocationService : public UBTService
{
	GENERATED_BODY()
		
//constructor
public:
	
	UBL_NewDodgeLocationService();
	
	

//c++ public methods
public:
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


//>>>................................................................................................>>>//


//Blueprint public values
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector DodgingTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector DodgeLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		float RandomRadius = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		float Range = 100.0f;

};
