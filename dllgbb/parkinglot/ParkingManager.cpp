#include "parkinglot.h"

class ParkingManager {

private:
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> availableSpots;
    unordered_map<shared_ptr<Vehicle>, shared_ptr<ParkingSpot>> occupiedSpots;

public:
    explicit ParkingManager(const unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>>& spots)
        : availableSpots(move(spots)) {}
    
    shared_ptr<ParkingSpot> findSpotForVehicle(const shared_ptr<Vehicle>& vehicle) {
        VehicleSize size = vehicle->getSize();
        
        // Iterate through sizes from smallest to largest for flexibility
        for (auto size: {VehicleSize::SMALL, VehicleSize::MEDIUM, VehicleSize::LARGE}) {
            if (size >= vehicle->getSize()) {
                auto& spots = availableSpots[size];
                for (const auto& spot : spots) {
                    if (spot->isAvailable()) {
                        return spot;
                    }
                }
            }
        }
        return nullptr;
    }

    shared_ptr<ParkingSpot> parkVehicle(const shared_ptr<Vehicle>& vehicle) {
        auto spot = findSpotForVehicle(vehicle);
        if (spot) {
            spot->occupy(vehicle);
            occupiedSpots[vehicle] = spot;
            return spot;
        }
        return nullptr;
    }

    void unparkVehicle(const shared_ptr<Vehicle>& vehicle) {
        auto it = occupiedSpots.find(vehicle);
        if (it != occupiedSpots.end()) {
            auto spot = it->second;
            spot->vacate();
            occupiedSpots.erase(it);
            availableSpots[spot->getSize()].push_back(spot);
        } else {
            throw runtime_error("Vehicle not found in expected occupied spots.");
        }
    }

};