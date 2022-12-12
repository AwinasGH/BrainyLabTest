// Fill out your copyright notice in the Description page of Project Settings.


#include "BrainyLabTest/Public/Components/WeaponComponent/BL_WeaponComponent.h"
#include "BrainyLabTest/Public/Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"

#include "GameFramework/Character.h"


UBL_WeaponComponent::UBL_WeaponComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UBL_WeaponComponent::Fire()
{
	if( const ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner()) )
	{
		if( !IsValid(OwnerCharacter->GetMesh()) ) return false;
		
		FVector SocketLocation = FVector::ZeroVector;
		FRotator SocketRotation = FRotator::ZeroRotator;
		OwnerCharacter->GetMesh()->GetSocketWorldLocationAndRotation(MuzzleSocketName, SocketLocation, SocketRotation);
		
		FActorSpawnParameters ActorSpawnParameters = FActorSpawnParameters();
		ActorSpawnParameters.Instigator = Cast<APawn>(GetOwner());
		
		ABL_BaseProjectile* SpawnedProjectile = Cast<ABL_BaseProjectile>(GetWorld()->SpawnActor(ProjectileToSpawnClass.LoadSynchronous(), &SocketLocation, &SocketRotation, ActorSpawnParameters));
		if( !IsValid(SpawnedProjectile) ) return false;
			
		ExistingProjectiles.Add(SpawnedProjectile);

		OnFired();

		return true;
	}

	return false;
}

void UBL_WeaponComponent::DestroyAllExistingProjectiles()
{
	if( ExistingProjectiles.Num() == 0 ) return;

	for( int i = 0; i < ExistingProjectiles.Num() && ExistingProjectiles.IsValidIndex(i); ++i )
	{
		if( IsValid(ExistingProjectiles[i]) ) ExistingProjectiles[i]->Destroy();
	}
}
