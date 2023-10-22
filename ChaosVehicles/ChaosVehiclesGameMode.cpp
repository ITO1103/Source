// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChaosVehiclesGameMode.h"
#include "ChaosVehiclesPawn.h"
#include "ChaosVehiclesHud.h"

AChaosVehiclesGameMode::AChaosVehiclesGameMode()
{
	DefaultPawnClass = AChaosVehiclesPawn::StaticClass();
	HUDClass = AChaosVehiclesHud::StaticClass();
}
