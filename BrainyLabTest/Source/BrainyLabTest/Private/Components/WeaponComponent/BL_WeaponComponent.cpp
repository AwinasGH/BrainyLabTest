// Fill out your copyright notice in the Description page of Project Settings.


#include "BrainyLabTest/Public/Components/WeaponComponent/BL_WeaponComponent.h"
#include "BrainyLabTest/Public/Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"

#include "GameFramework/Character.h"


UBL_WeaponComponent::UBL_WeaponComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UBL_WeaponComponent::Fire()
{
	if( const ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner()) )
	{
		if( !IsValid(OwnerCharacter->GetMesh()) ) return;
		
		FVector SocketLocation = FVector::ZeroVector;
		FRotator SocketRotation = FRotator::ZeroRotator;
		OwnerCharacter->GetMesh()->GetSocketWorldLocationAndRotation(MuzzleSocketName, SocketLocation, SocketRotation);
		
		FActorSpawnParameters ActorSpawnParameters = FActorSpawnParameters();
		ActorSpawnParameters.Instigator = Cast<APawn>(GetOwner());
		
		//const FRotator SocketForwardRotation = FRotator(0.0f, 0.0f, SocketRotation.Roll);
		
		GetWorld()->SpawnActor(ProjectileToSpawnClass.LoadSynchronous(), &SocketLocation, &SocketRotation, ActorSpawnParameters);

		OnFired();
	}
}
