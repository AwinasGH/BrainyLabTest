// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BL_GameScoreWD.generated.h"


class UTextBlock;
class ABL_GameHUD;

/*
	
*/
UCLASS(Abstract)
class BRAINYLABTEST_API UBL_GameScoreWD : public UUserWidget
{
	GENERATED_BODY()
	
//constructor
public:

	UBL_GameScoreWD(const FObjectInitializer& ObjectInitializer);

	
//c++ protected methods
protected:

	virtual void NativeConstruct() override;

//c++ private methods
private:
	
	UFUNCTION()
		void OnScoreChanged(int PlayerScore, int EnemyScore);
	
//>>.................................................................................................................................................<<//


//Blueprint methods
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameScoreWD")
		void InitializeGameScoreWD(ABL_GameHUD* InGameHUD);
		virtual void InitializeGameScoreWD_Implementation(ABL_GameHUD* InGameHUD);


//Blueprint values
public:

	/*
		Current score text block
	*/
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "GameScore|Widgets")
		UTextBlock* ScoreText = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
		ABL_GameHUD* GameHUD = nullptr;
};
