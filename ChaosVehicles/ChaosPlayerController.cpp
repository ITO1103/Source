// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaosPlayerController.h"
#include "ChaosVehiclesPawn.h"

void AChaosPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Bind the Enter key to a custom function
	//InputComponent->BindAction("Enter", IE_Pressed, this, &AChaosPlayerController::OnEnterKeyPressed);
    InputComponent->BindAction("Enter", IE_Pressed, this, &AChaosPlayerController::OnEnterKeyPressed);
}

void AChaosPlayerController::OnEnterKeyPressed()
{
    // Implement the logic to reset the car's orientation here
    AChaosVehiclesPawn* ControlledCar = Cast<AChaosVehiclesPawn>(GetPawn());

    if (ControlledCar)
    {
        // Call the ResetCarOrientation method to flip the car back to its upright position
        ControlledCar->ResetCarOrientation();
    }
}
