// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BL_BaseCharacter.generated.h"


class UBehaviorTree;

/*
	Base class for all characters in game.
*/
UCLASS(Abstract)
class BRAINYLABTEST_API ABL_BaseCharacter : public ACharacter
{
	GENERATED_BODY()


	
//constructor
public:

	ABL_BaseCharacter(const FObjectInitializer& ObjectInitializer);

	

//>>>...............................................................................................................................................................................<<<//
	
	
//Blueprint public values:
public:
	
//.................................Components.....................................................//
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter|Components|WeaponComponent")
		class UBL_WeaponComponent* WeaponComponent = nullptr;

//................................................................................................//

	
};
