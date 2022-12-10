// Fill out your copyright notice in the Description page of Project Settings.


#include "BrainyLabTest/Public/UI/GameScoreWD/BL_GameScoreWD.h"

#include "BrainyLabTest/Public/GameMode/BL_GameHUD.h"


UBL_GameScoreWD::UBL_GameScoreWD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsFocusable = false;
}

void UBL_GameScoreWD::NativeConstruct()
{
	Super::NativeConstruct();

	
}

void UBL_GameScoreWD::InitializeGameScoreWD_Implementation(ABL_GameHUD* InGameHUD)
{
	if( IsValid(InGameHUD) ) GameHUD = InGameHUD;
}
