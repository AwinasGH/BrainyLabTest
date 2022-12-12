// Fill out your copyright notice in the Description page of Project Settings.


#include "BrainyLabTest/Public/UI/GameScoreWD/BL_GameScoreWD.h"

#include "BrainyLabTest/Public/GameMode/BL_GameHUD.h"
#include "Components/TextBlock.h"
#include "GameMode/BL_GameModeBase.h"
#include "Kismet/GameplayStatics.h"


UBL_GameScoreWD::UBL_GameScoreWD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsFocusable = false;
}

void UBL_GameScoreWD::NativeConstruct()
{
	Super::NativeConstruct();

	if( IsValid(ScoreText) ) ScoreText->SetText(FText::FromString(FString::FromInt(0) + ":" + FString::FromInt(0)));

	ABL_GameModeBase* GameMode = Cast<ABL_GameModeBase>(UGameplayStatics::GetGameMode(GetOwningPlayerPawn()));
	if( !IsValid(GameMode) ) return;

	GameMode->OnScoreChangedBind.AddDynamic(this, &UBL_GameScoreWD::OnScoreChanged);
}

void UBL_GameScoreWD::OnScoreChanged(int PlayerScore, int EnemyScore)
{
	if( IsValid(ScoreText) ) ScoreText->SetText(FText::FromString(FString::FromInt(PlayerScore) + ":" + FString::FromInt(EnemyScore)));
}

void UBL_GameScoreWD::InitializeGameScoreWD_Implementation(ABL_GameHUD* InGameHUD)
{
	if( IsValid(InGameHUD) ) GameHUD = InGameHUD;
}
