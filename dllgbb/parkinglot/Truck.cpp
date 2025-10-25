#include "parkinglot.h"

// Concrete implementation of Vehicle class for Truck
class Truck : public Vehicle {
private:
    string licensePlate;

public:
    explicit Truck(const string& plate) : licensePlate(plate) {}

    VehicleSize getSize() const override {
        return VehicleSize::LARGE; // Trucks are considered large-sized vehicles
    }

    string getLicensePlate() const override {
        return licensePlate;
    }
};