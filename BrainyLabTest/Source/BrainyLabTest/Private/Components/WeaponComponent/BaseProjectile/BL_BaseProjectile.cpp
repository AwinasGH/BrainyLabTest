
#include "BrainyLabTest/Public/Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Prediction.h"
#include "Perception/AISense_Sight.h"

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
	
	AIStimuliComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>("AIStimuliSourceComponent");
	AIStimuliComponent->RegisterForSense(UAISense_Sight::StaticClass());
	AIStimuliComponent->RegisterForSense(UAISense_Prediction::StaticClass());
}
