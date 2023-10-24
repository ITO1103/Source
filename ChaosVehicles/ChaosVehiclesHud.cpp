// Copyright Epic Games, Inc and EDP-KEN. All Rights Reserved.
// edp-ken.com

#include <iostream>
#include "ChaosVehiclesHud.h"
#include "ChaosVehiclesPawn.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

// Needed for VR Headset
#include "Engine.h"

#define LOCTEXT_NAMESPACE "VehicleHUD"

#ifndef HMD_MODULE_INCLUDED
#define HMD_MODULE_INCLUDED 0
#endif

AChaosVehiclesHud::AChaosVehiclesHud()
{
    static ConstructorHelpers::FObjectFinder<UFont> Font(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
    HUDFont = Font.Object;
}

void AChaosVehiclesHud::DrawHUD()
{
    Super::DrawHUD();

    // Calculate ratio from 1080p
    const float HUDXRatio = Canvas->SizeX / 1920.f;
    const float HUDYRatio = Canvas->SizeY / 1080.f;

    bool bHMDDeviceActive = false;

    ElapsedTime += GetWorld()->GetDeltaSeconds();
    //float TotalTimeElapsed = 0;

    // We dont want the onscreen hud when using a HMD device    
#if HMD_MODULE_INCLUDED
    bHMDDeviceActive = GEngine->IsStereoscopic3D();
#endif // HMD_MODULE_INCLUDED
    if (bHMDDeviceActive == false)
    {
        // Get our vehicle so we can check if we are in car. If we are we don't want onscreen HUD
        AChaosVehiclesPawn* Vehicle = Cast<AChaosVehiclesPawn>(GetOwningPawn());
        if ((Vehicle != nullptr) && (Vehicle->bInCarCameraActive == false))
        {
            FVector2D ScaleVec(HUDYRatio * 2.4f, HUDYRatio * 2.4f);

            // Speed
            FCanvasTextItem SpeedTextItem(FVector2D(HUDXRatio * 1500.f, HUDYRatio * 800), Vehicle->SpeedDisplayString, HUDFont, FLinearColor::White);
            SpeedTextItem.Scale = ScaleVec;
            Canvas->DrawItem(SpeedTextItem);

            // Gear
            FCanvasTextItem GearTextItem(FVector2D(HUDXRatio * 1500.f, HUDYRatio * 860.f), Vehicle->GearDisplayString, HUDFont, Vehicle->bInReverseGear == false ? Vehicle->GearDisplayColor : Vehicle->GearDisplayReverseColor);
            GearTextItem.Scale = ScaleVec;
            Canvas->DrawItem(GearTextItem);

            // Elapsed Time (Fixed position)
            float TotalTimeElapsed = ElapsedTime; // 経過時間を秒単位で表す変数
            int32 Minutes = FMath::FloorToInt(TotalTimeElapsed / 60); // 分単位の経過時間
            float Seconds = FMath::Fmod(TotalTimeElapsed, 60); // 秒単位の経過時間

            /*FString ElapsedTimeText;
            if (Minutes > 0){
                ElapsedTimeText = FString::Printf(TEXT("Time: %2d:%2.3f seconds"), Minutes, Seconds);
            }
            else{
                ElapsedTimeText = FString::Printf(TEXT("Time: %.3f seconds"), Seconds);
            }*/
            FString ElapsedTimeText;
            
            // 分が1桁の場合は0で埋める
            FString PaddedMinutes = FString::Printf(TEXT("%02d"), Minutes);

            // 秒の２桁目を0埋め＆小数点第3位まで表示
            FString PaddedSeconds = FString::Printf(TEXT("%06.3f"), Seconds);

            ElapsedTimeText = FString::Printf(TEXT("Time: %s'%s"), *PaddedMinutes, *PaddedSeconds);
            


            FVector2D ElapsedTimePos(HUDXRatio * 1500.f, HUDYRatio * 920.f);
            FCanvasTextItem ElapsedTimeTextItem(ElapsedTimePos, FText::FromString(ElapsedTimeText), HUDFont, FLinearColor::White);
            ElapsedTimeTextItem.Scale = ScaleVec;
            Canvas->DrawItem(ElapsedTimeTextItem);
        }
    }
}