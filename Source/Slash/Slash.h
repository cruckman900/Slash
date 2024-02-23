// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// Defining functions for drawing debug objects that can be used anywhere
#define DRAW_SPHERE(Location, Color) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, Color, true);
#define DRAW_LINE(StartLocation, EndLocation, Color) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, Color, true, -1.f, 0, 1.f);