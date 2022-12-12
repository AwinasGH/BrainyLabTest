
#include "BrainyLabTest/Public/Character/Player/BL_PlayerCharacter.h"

#include "BrainyLabTest/Public/Components/WeaponComponent/BL_WeaponComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Prediction.h"
#include "Perception/AISense_Sight.h"


ABL_PlayerCharacter::ABL_PlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GetCharacterMovement()->bOrientRotationToMovement = false;

	TopDownCamera = CreateDefaultSubobject<UCameraComponent>("TopDownCamera");
	TopDownCamera->bUsePawnControlRotation = false;
	TopDownCamera->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	TopDownCamera->SetActive(true);

	AIStimuliComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>("AIStimuliSourceComponent");
	AIStimuliComponent->RegisterForSense(UAISense_Sight::StaticClass());
	AIStimuliComponent->RegisterForSense(UAISense_Prediction::StaticClass());
}

void ABL_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//................Moving................//

	PlayerInputComponent->BindAxis("MoveForward/Back", this, &ABL_PlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight/Left", this, &ABL_PlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnRight/Left", this, &ABL_PlayerCharacter::LookRight);

	//......................................//

	//..........Gameplay Actions............//

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ABL_PlayerCharacter::PressFireAction);

	//......................................//
}

void ABL_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	TopDownCamera->SetWorldTransform(CameraWorldTransform);
}


void ABL_PlayerCharacter::MoveForward(float AxisValue)
{
	if( FMath::IsNearlyZero(AxisValue) ) return;
	
	AddMovementInput(TopDownCamera->GetUpVector(), AxisValue);
}

void ABL_PlayerCharacter::MoveRight(float AxisValue)
{
	if( FMath::IsNearlyZero(AxisValue) ) return;
		
	AddMovementInput(TopDownCamera->GetRightVector(), AxisValue);
}

void ABL_PlayerCharacter::LookRight(float AxisValue)
{
	if( FMath::IsNearlyZero(AxisValue) ) return;

	this->AddControllerYawInput(AxisValue);
}


void ABL_PlayerCharacter::PressFireAction()
{
	WeaponComponent->Fire();
}
