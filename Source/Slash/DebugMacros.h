#pragma once
#include "DrawDebugHelpers.h"

// Defining functions for writing, logging, or drawing debug objects
#define PRINT_TO_SCREEN(Key, Color, Message) if (GEngine) GEngine->AddOnScreenDebugMessage(Key, 60.f, Color, Message);
#define PRINT_TO_LOG(Verbosity, Message) UE_LOG(LogTemp, Verbosity, Message);

#define DRAW_SPHERE(Location, Color) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, Color, true);
#define DRAW_LINE(StartLocation, EndLocation, Color) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, Color, true, -1.f, 0, 1.f);
#define DRAW_POINT(Location, Color) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, Color, true);
#define DRAW_VECTOR(StartLocation, EndLocation, Color) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, Color, true, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, Color, true); \
	}
