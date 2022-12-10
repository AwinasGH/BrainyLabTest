// Fill out your copyright notice in the Description page of Project Settings.


#include "BrainyLabTest/Public/GameMode/BL_GameHUD.h"

#include "BrainyLabTest/Public/UI/GameScoreWD/BL_GameScoreWD.h"


ABL_GameHUD::ABL_GameHUD(const FObjectInitializer& ObjectInitializer)
{
	
}

void ABL_GameHUD::CreateGameScoreWD()
{
	if( !GameScoreWDClass.IsNull() && GameScoreWD == nullptr )
	{
		GameScoreWD = CreateWidget<UBL_GameScoreWD>(GetWorld(), GameScoreWDClass.LoadSynchronous());
		if( IsValid(GameScoreWD) )
		{
			GameScoreWD->AddToViewport();
		}
	}
}

void ABL_GameHUD::RemoveGameScoreWD()
{
	if( IsValid(GameScoreWD) )
	{
		GameScoreWD->RemoveFromParent();
		GameScoreWD = nullptr;
	}
}
