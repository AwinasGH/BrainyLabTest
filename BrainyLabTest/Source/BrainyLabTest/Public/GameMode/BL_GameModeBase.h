// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BL_GamemodeBase.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProjectileHit, AActor*, HitActor)



/*
	
*/
UCLASS()
class BRAINYLABTEST_API ABL_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

//constructor
public:

	ABL_GameModeBase();
	
//c++ public methods
public:

	


//>>.................................................................................................................................................<<//


//Blueprint methods
public:

	UPROPERTY(BlueprintAssignable, Category = "GameStartup")
		FOnProjectileHit OnGameStartedBind;
};
