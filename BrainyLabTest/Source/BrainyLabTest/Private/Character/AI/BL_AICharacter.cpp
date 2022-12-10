
#include "BrainyLabTest/Public/Character/AI/BL_AICharacter.h"

#include "Character/AI/Controllers/BL_BaseAIController.h"
#include "GameFramework/CharacterMovementComponent.h"


ABL_AICharacter::ABL_AICharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ABL_BaseAIController::StaticClass();

	bUseControllerRotationYaw = false;
	if ( UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement() ) 
	{
		CharacterMovementComponent->bUseControllerDesiredRotation = true;
		CharacterMovementComponent->RotationRate = FRotator(0.f,200.f,0.f);
	}
}
