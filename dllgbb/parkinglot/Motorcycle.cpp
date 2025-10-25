#include "parkinglot.h"

// Concrete implementation of Vehicle class for Motorcycle
class Motorcycle : public Vehicle {
private:
    string licensePlate;

public:
    explicit Motorcycle(const string& plate) : licensePlate(plate) {}

    VehicleSize getSize() const override {
        return VehicleSize::SMALL; // Motorcycles are considered small-sized vehicles
    }

    string getLicensePlate() const override {
        return licensePlate;
    }
};