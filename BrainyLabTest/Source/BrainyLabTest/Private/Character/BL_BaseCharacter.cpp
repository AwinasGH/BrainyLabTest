#include "BrainyLabTest/Public/Character/BL_BaseCharacter.h"

#include "BrainyLabTest/Public/Components/WeaponComponent/BL_WeaponComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WeaponComponent/BaseProjectile/BL_BaseProjectile.h"
#include "GameMode/BL_GameModeBase.h"
#include "Kismet/GameplayStatics.h"


ABL_BaseCharacter::ABL_BaseCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponComponent = CreateDefaultSubobject<UBL_WeaponComponent>("WeaponComponent");
}

void ABL_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ABL_BaseCharacter::OnCapsuleHit);

	InitialSpawnLocation = GetActorLocation();

	ABL_GameModeBase* GameMode = Cast<ABL_GameModeBase>(UGameplayStatics::GetGameMode(this));
	if( !IsValid(GameMode) ) return;

	GameMode->OnScoreChangedBind.AddDynamic(this, &ABL_BaseCharacter::CharacterToDefaultCondition);
}

void ABL_BaseCharacter::OnCapsuleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if( IsValid(OtherActor) && OtherActor->GetClass()->IsChildOf(ABL_BaseProjectile::StaticClass()) )
	{
		ABL_GameModeBase* GameMode = Cast<ABL_GameModeBase>(UGameplayStatics::GetGameMode(this));
		if( !IsValid(GameMode) ) return;

		GameMode->ChangeScore(this);
	}
}

void ABL_BaseCharacter::CharacterToDefaultCondition(int PlayerScore, int EnemyScore)
{
	SetActorLocation(InitialSpawnLocation);

	WeaponComponent->DestroyAllExistingProjectiles();
}




