// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BL_SetEnemyService.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_SetEnemyService : public UBTService
{
	GENERATED_BODY()

	
//constructor
public:
	
	UBL_SetEnemyService();

//c++ public methods
public:
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


//>>>................................................................................................>>>//


//Blueprint public values
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector EnemyActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI | BlackboardKey")
		FBlackboardKeySelector ProjectileActor;
};
