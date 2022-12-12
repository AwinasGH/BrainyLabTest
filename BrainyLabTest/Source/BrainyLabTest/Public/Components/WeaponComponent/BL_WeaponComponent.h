// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BL_WeaponComponent.generated.h"


class ABL_BaseProjectile;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BRAINYLABTEST_API UBL_WeaponComponent : public UActorComponent
{
	GENERATED_BODY()
	
//constructor
public:

	UBL_WeaponComponent(const FObjectInitializer& ObjectInitializer);
	
	
//constructor
public:

	UPROPERTY(Transient)
		TArray<ABL_BaseProjectile*> ExistingProjectiles;


//>>>...............................................................................................................................................................................<<<//

	
//Blueprint public methods:
public:

	UFUNCTION(BlueprintCallable, Category = "WeaponComponent|Fire")
		virtual bool Fire();

	UFUNCTION(BlueprintCallable, Category = "WeaponComponent|Projectiles")
		void DestroyAllExistingProjectiles();

//Blueprint protected methods:
protected:

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected), BlueprintNativeEvent, Category = "WeaponComponent|Fire")
		void OnFired();
		virtual void OnFired_Implementation(){};


//Blueprint public values:
public:

	/*
		Projectile to spawn class
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponComponent|Default")
		TSoftClassPtr<ABL_BaseProjectile> ProjectileToSpawnClass = nullptr;
	/*
		Muzzle socket name. The starting point of the projectile
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponComponent|Default")
		FName MuzzleSocketName = NAME_None;

};
