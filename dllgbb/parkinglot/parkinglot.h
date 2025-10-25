#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <bits/stdc++.h>
using namespace std;

// CRITICAL: Include order matters!
// 1. First, include VehicleSize enum (no dependencies)
#include "VehicleSize.cpp"

// 2. Then Vehicle (depends on VehicleSize)
#include "Vehicle.cpp"

// 3. Then ParkingSpot (depends on VehicleSize and Vehicle)
#include "ParkingSpot.cpp"

// 4. Then concrete vehicle classes (depend on Vehicle and VehicleSize)
#include "Motorcycle.cpp"
#include "Car.cpp"
#include "Truck.cpp"

// 5. Then concrete spot classes (depend on ParkingSpot)
#include "CompactSpot.cpp"
#include "RegularSpot.cpp"
#include "OversizedSpot.cpp"

// 6. Then Ticket (depends on Vehicle and ParkingSpot)
#include "Ticket.cpp"

// 7. Then FareStrategy (depends on Ticket)
#include "FareStrategy.cpp"
#include "BaseFareStrategy.cpp"
#include "PeakHoursFareStrategy.cpp"

// 8. Then FareCalculator (depends on FareStrategy)
#include "FareCalculator.cpp"

// 9. Then ParkingManager (depends on Vehicle and ParkingSpot)
#include "ParkingManager.cpp"

// 10. Finally ParkingLot (depends on everything)
#include "ParkingLot.cpp"

#endif