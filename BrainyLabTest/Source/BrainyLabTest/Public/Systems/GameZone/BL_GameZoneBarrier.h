// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BL_GameZoneBarrier.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class BRAINYLABTEST_API ABL_GameZoneBarrier : public AActor
{
	GENERATED_BODY()
	
//constructor
public:

	ABL_GameZoneBarrier(const FObjectInitializer& ObjectInitializer);

	
//c++ protected
protected:

	virtual void BeginPlay() override;

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

//>>>...............................................................................................................................................................................<<<//

	
//Blueprint values
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameZone|Components")
		class UBoxComponent* BoxComponent = nullptr;
};
