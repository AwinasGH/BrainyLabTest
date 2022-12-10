
#include "BrainyLabTest/Public/Systems/GameZone/BL_GameZoneBarrier.h"

#include "BrainyLabTest/Public/Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"

#include "Components/BoxComponent.h"

ABL_GameZoneBarrier::ABL_GameZoneBarrier(const FObjectInitializer& ObjectInitializer)
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BarrierCollision");
	SetRootComponent(BoxComponent);
}

void ABL_GameZoneBarrier::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABL_GameZoneBarrier::OnBeginOverlap);
}

void ABL_GameZoneBarrier::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if( OtherActor->GetClass()->IsChildOf(ABL_BaseProjectile::StaticClass()) )
	{
		OtherActor->Destroy();
	}
}



