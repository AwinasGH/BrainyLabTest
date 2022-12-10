// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BL_GameScoreWD.generated.h"


class ABL_GameHUD;

/*
	
*/
UCLASS()
class BRAINYLABTEST_API UBL_GameScoreWD : public UUserWidget
{
	GENERATED_BODY()
	
//constructor
public:

	UBL_GameScoreWD(const FObjectInitializer& ObjectInitializer);

	
//c++ protected methods
protected:

	virtual void NativeConstruct() override;

	
//c++ values
private:

	int PlayerScore = 0;
	
	int EnemyScore = 0;
	
//>>.................................................................................................................................................<<//


//Blueprint methods
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameScoreWD")
		void InitializeGameScoreWD(ABL_GameHUD* InGameHUD);
		virtual void InitializeGameScoreWD_Implementation(ABL_GameHUD* InGameHUD);


//Blueprint values
public:
	
	UPROPERTY(BlueprintReadOnly)
		ABL_GameHUD* GameHUD = nullptr;
};
