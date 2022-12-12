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


//c++ protected methods
protected:

	virtual void BeginPlay() override;

	UFUNCTION()
		void OnCapsuleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	

//c++ private values
private:

	FVector InitialSpawnLocation = FVector::ZeroVector;
	
//>>>...............................................................................................................................................................................<<<//
	
//Blueprint public methods:
public:

	UFUNCTION(BlueprintCallable, Category = "PlayerCharacter|InitialSpawnLocation")
		const FVector& GetInitialSpawnLocation() const { return InitialSpawnLocation; }
	
	UFUNCTION(BlueprintCallable, Category = "PlayerCharacter|InitialSpawnLocation")
		void CharacterToDefaultCondition(int PlayerScore, int EnemyScore);

	
//Blueprint public values:
public:
	
//.................................Components.....................................................//
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter|Components|WeaponComponent")
		class UBL_WeaponComponent* WeaponComponent = nullptr;

//................................................................................................//

	
};

