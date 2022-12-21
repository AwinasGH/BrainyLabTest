// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BL_BaseCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "BL_GamemodeBase.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScoreChanged, int, PlayerScore, int, EnemyScore)



/*
	
*/
UCLASS()
class BRAINYLABTEST_API ABL_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

//constructor
public:

	ABL_GameModeBase();
	
//c++ private values
private:

	int32 PlayerScore = 0;
	
	int32 EnemyScore = 0;

	
//>>.................................................................................................................................................<<//


//Blueprint methods
public:
	
	UFUNCTION(BlueprintCallable, Category = "GameScore")
		void ChangeScore(const ABL_BaseCharacter* HitActor);

//Blueprint protected
protected:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameScore")
		void OnScoreChanged();
		virtual void OnScoreChanged_Implementation();

//Blueprint values
public:
	
	UPROPERTY(BlueprintAssignable, Category = "GameScore")
		FOnScoreChanged OnScoreChangedBind;
};
