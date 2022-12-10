// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainyLabTest/Public/Character/BL_BaseCharacter.h"
#include "BL_AICharacter.generated.h"

/*
	
*/
UCLASS()
class BRAINYLABTEST_API ABL_AICharacter : public ABL_BaseCharacter
{
	GENERATED_BODY()
	
//constructor
public:

	ABL_AICharacter(const FObjectInitializer& ObjectInitializer);
	

//>>>...............................................................................................................................................................................<<<//
	
	
//Blueprint public values:
public:

	/*
		BT asset for initializing AI.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AIBase | Default")
		UBehaviorTree* BehaviorTree = nullptr;
};

