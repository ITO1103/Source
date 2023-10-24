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
	//�@���[�U�[���͂̂��߂̃��]�b�g��錾
	void SetupInputComponent() override;
	//�@�J�X�^���̃L�[�C�x���g�n���h����錾
	void OnEnterKeyPressed();
	
};
