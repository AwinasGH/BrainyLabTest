// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BL_BaseProjectile.generated.h"

UCLASS(Abstract)
class BRAINYLABTEST_API ABL_BaseProjectile : public AActor
{
	GENERATED_BODY()
	

//constructor
public:

	ABL_BaseProjectile();

//>>....................................................................................................................................................................<<//
	

//Blueprint public methods
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseProjectile|Components")
		class UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseProjectile|Components")
		class UStaticMeshComponent* StaticMeshComponent = nullptr;
};
