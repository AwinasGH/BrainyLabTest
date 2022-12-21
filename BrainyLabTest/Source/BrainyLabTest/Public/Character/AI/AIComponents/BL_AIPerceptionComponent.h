// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Perception/AIPerceptionComponent.h"

#include "BL_AIPerceptionComponent.generated.h"


class ABL_BaseProjectile;
class ABL_BaseCharacter;
class UAISense_Sight;



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
	
	template <typename SenseType, typename ClassSearch>
	UFUNCTION(BlueprintCallable, Category = "AI")
		AActor* GetClosestPerceiver(AActor* ChachedVariable);

	UFUNCTION(BlueprintCallable, Category = "AI")
		FORCEINLINE AActor* GetClosestEnemy() { return GetClosestPerceiver<UAISense_Sight, ABL_BaseCharacter>(CurrentEnemy); };

	UFUNCTION(BlueprintCallable, Category = "AI")
		FORCEINLINE AActor* GetClosestProjectile() { return GetClosestPerceiver<UAISense_Sight, ABL_BaseProjectile>(CurrentEnemy); };
};


