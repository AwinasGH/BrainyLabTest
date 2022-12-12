// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BehaviorTree/BehaviorTreeTypes.h"

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

	

//c++ protected values	
protected:

	virtual void BeginPlay() override;

	
//c++ private values	
private:

	UFUNCTION()
		void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);


//c++ protected values	
protected:

	UPROPERTY()
		AActor* CurrentEnemy = nullptr;

	UPROPERTY()
		AActor* CurrentProjectile = nullptr;


//>>>................................................................................................>>>//


//Blueprint public values
public:

	/*
		Prediction time for sense
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|Senses|Prediction")
		float PredictionTime = 0.1f;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI|BlackboardKey")
		FName EnemyActorKeyName = NAME_None;


//Blueprint public methods
public:


	UFUNCTION(BlueprintCallable, Category = "AI")
		AActor* GetClosestEnemy();

	UFUNCTION(BlueprintCallable, Category = "AI")
		AActor* GetClosestProjectile();
};
