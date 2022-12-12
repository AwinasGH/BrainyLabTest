// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainyLabTest/Public/GameMode/BL_GameModeBase.h"

#include "Character/Player/BL_PlayerCharacter.h"
#include "Character/Player/BL_PlayerController.h"

#include "GameMode/BL_GameHUD.h"
#include "Kismet/GameplayStatics.h"


ABL_GameModeBase::ABL_GameModeBase()
{
	DefaultPawnClass = ABL_BaseCharacter::StaticClass();
	HUDClass = ABL_GameHUD::StaticClass();
	PlayerControllerClass = ABL_PlayerController::StaticClass();
}

void ABL_GameModeBase::ChangeScore(const ABL_BaseCharacter* HitActor)
{
	if( HitActor->IsA(ABL_PlayerCharacter::StaticClass()) )
	{
		++EnemyScore;
	}
	else
	{
		++PlayerScore;
	}

	OnScoreChanged();
}


void ABL_GameModeBase::OnScoreChanged_Implementation()
{
	OnScoreChangedBind.Broadcast(PlayerScore, EnemyScore);
}
