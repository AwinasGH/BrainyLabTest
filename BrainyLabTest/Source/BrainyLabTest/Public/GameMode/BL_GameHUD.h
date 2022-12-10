// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BL_GameHUD.generated.h"


class UBL_GameScoreWD;

/*
	
*/
UCLASS()
class BRAINYLABTEST_API ABL_GameHUD : public AHUD
{
	GENERATED_BODY()

//constructor
public:

	ABL_GameHUD(const FObjectInitializer& ObjectInitializer);

	

//>>.................................................................................................................................................<<//
	

//Blueprint methods
public:

	UFUNCTION(BlueprintCallable, Category = "GameScoreWD")
		void CreateGameScoreWD();
	UFUNCTION(BlueprintCallable, Category = "GameScoreWD")
		void RemoveGameScoreWD();

	
//Blueprint protected values
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSoftClassPtr<UBL_GameScoreWD> GameScoreWDClass;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
		UBL_GameScoreWD* GameScoreWD = nullptr;
};
