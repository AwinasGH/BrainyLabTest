// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "BL_AIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API UBL_AIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

//constructor
public:
	
	UBL_AIPerceptionComponent(const FObjectInitializer& ObjectInitializer);

	
//c++ public methods
public:
	

	UFUNCTION(BlueprintCallable, Category = "AI")
		AActor* GetClosestEnemy();


//c++ protected values	
protected:

	UPROPERTY()
		AActor* CurrentEnemy = nullptr;
	
};
