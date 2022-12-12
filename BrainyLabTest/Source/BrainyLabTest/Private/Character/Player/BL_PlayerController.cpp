// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/BL_PlayerController.h"

#include "GameMode/BL_GameHUD.h"

ABL_PlayerController::ABL_PlayerController()
{
	
}

void ABL_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	MyGameHUD = Cast<ABL_GameHUD>(GetHUD());

	if( IsValid(MyGameHUD) ) MyGameHUD->CreateGameScoreWD();
}

