#include "parkinglot.h"

// Concrete implementation of ParkingSpot for large vehicles
class OversizedSpot : public ParkingSpot {
private:
    int spotNumber;
    shared_ptr<Vehicle> vehicle;

public:
    explicit OversizedSpot(int number) : spotNumber(number), vehicle(nullptr) {}

    bool isAvailable() const override {
        return vehicle == nullptr;
    }

    VehicleSize getSize() const override {
        return VehicleSize::LARGE;
    }

    void occupy(shared_ptr<Vehicle> vehicle) override {
        if (isAvailable()) {
            this->vehicle = vehicle;
        } else {
            throw runtime_error("Cannot occupy oversized spot: spot already occupied.");
        }
    }

    void vacate() override {
        vehicle = nullptr;
    }

    int getSpotNumber() const override {
        return spotNumber;
    }
};