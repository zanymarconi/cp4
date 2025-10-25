#include "parkinglot.h"

// Concrete implementation of Vehicle class for Car
class Car : public Vehicle {
private:
    string licensePlate;

public:
    explicit Car(const string& plate) : licensePlate(plate) {}
    
    VehicleSize getSize() const override {
        return VehicleSize::MEDIUM; // Cars are considered medium-sized vehicles
    }

    string getLicensePlate() const override {
        return licensePlate;
    }
};