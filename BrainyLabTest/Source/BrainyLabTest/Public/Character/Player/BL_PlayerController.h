// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BL_PlayerController.generated.h"

class ABL_GameHUD;

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API ABL_PlayerController : public APlayerController
{
	GENERATED_BODY()

//public
public:

	ABL_PlayerController();


//c++ protected methods
protected:

	virtual void BeginPlay() override;


//Blueprint values
public:
	
	UPROPERTY(BlueprintReadOnly, Category = "PlayerController")
		ABL_GameHUD* MyGameHUD = nullptr;
};
