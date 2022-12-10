#include "BrainyLabTest/Public/Character/BL_BaseCharacter.h"

#include "BrainyLabTest/Public/Components/WeaponComponent/BL_WeaponComponent.h"


ABL_BaseCharacter::ABL_BaseCharacter(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponComponent = CreateDefaultSubobject<UBL_WeaponComponent>("WeaponComponent");
}




