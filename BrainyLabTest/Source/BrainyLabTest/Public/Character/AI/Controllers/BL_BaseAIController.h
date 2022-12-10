// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BL_BaseAIController.generated.h"

class UBL_AIPerceptionComponent;

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API ABL_BaseAIController : public AAIController
{
	GENERATED_BODY()
	
//constructor
public:

	ABL_BaseAIController();


//c++ protected methods
protected:
	
	virtual void OnPossess(APawn* InPawn) override;


//>>>................................................................................................>>>//
	
	
//Blueprint protected values
protected:

	/*
		Component for targeting. Sight is dominant
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseAI|Components")
		UBL_AIPerceptionComponent* AIPerceptionComponent = nullptr;
};
