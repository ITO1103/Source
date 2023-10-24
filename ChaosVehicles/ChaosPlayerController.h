// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChaosPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHAOSVEHICLES_API AChaosPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//　ユーザー入力のためのメゾットを宣言
	void SetupInputComponent() override;
	//　カスタムのキーイベントハンドラを宣言
	void OnEnterKeyPressed();
	
};
