// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ChaosVehiclesHud.generated.h"

UCLASS(config = Game)
class AChaosVehiclesHud : public AHUD
{
	GENERATED_BODY()

public:
	AChaosVehiclesHud();

	float ElapsedTime = 0.0f;

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

};
