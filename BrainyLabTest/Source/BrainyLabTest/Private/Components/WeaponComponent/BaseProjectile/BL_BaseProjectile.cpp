
#include "BrainyLabTest/Public/Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

ABL_BaseProjectile::ABL_BaseProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovementComponent->bRotationFollowsVelocity = false;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	ProjectileMovementComponent->Bounciness = 1.0f;
	ProjectileMovementComponent->Friction = 0.0f;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMeshComponent);
}
