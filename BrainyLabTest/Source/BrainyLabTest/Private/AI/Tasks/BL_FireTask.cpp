#include "AI/Tasks/BL_FireTask.h"

#include "AIController.h"
#include "Character/AI/BL_AICharacter.h"

#include "Components/WeaponComponent/BL_WeaponComponent.h"


UBL_FireTask::UBL_FireTask()
{
	NodeName = "Fire Task";
}

EBTNodeResult::Type UBL_FireTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if( const AAIController* Controller = OwnerComp.GetAIOwner() )
	{
		const ABL_AICharacter* Character = Cast<ABL_AICharacter>(Controller->GetPawn());
		if( !IsValid(Character) ) return EBTNodeResult::Failed;
		
		Character->WeaponComponent->Fire();
		
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
