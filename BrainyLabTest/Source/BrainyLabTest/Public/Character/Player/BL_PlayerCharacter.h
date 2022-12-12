#pragma once

#include "CoreMinimal.h"
#include "BrainyLabTest/Public/Character/BL_BaseCharacter.h"
#include "BL_PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BRAINYLABTEST_API ABL_PlayerCharacter : public ABL_BaseCharacter
{
	GENERATED_BODY()


//constructor
public:

	ABL_PlayerCharacter(const FObjectInitializer& ObjectInitializer);
	

//c++ protected methods
protected:
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay() override;

//c++ public methods
public:

	//..........Moving..............//

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void LookRight(float AxisValue);

	//.............................//

	//..........Gameplay Actions............//

	void PressFireAction();

	//......................................//


//>>>...............................................................................................................................................................................<<<//

	
//Blueprint values
public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacter|Components|Camera")
		FTransform CameraWorldTransform = FTransform::Identity;
	
	
//.................................Components.....................................................//
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter|Components")
		class UCameraComponent* TopDownCamera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter|Components")
		class UAIPerceptionStimuliSourceComponent* AIStimuliComponent = nullptr;

//................................................................................................//

};
