// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainyLabTest/Public/GameMode/BL_GameModeBase.h"

#include "BrainyLabTest/Public/Character/BL_BaseCharacter.h"


ABL_GameModeBase::ABL_GameModeBase()
{
	DefaultPawnClass = ABL_BaseCharacter::StaticClass();
//	HUDClass = ABL_GameHUD::StaticClass();
}
