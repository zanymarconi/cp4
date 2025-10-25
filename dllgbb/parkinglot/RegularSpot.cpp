#include "parkinglot.h"

// Concrete implementation of ParkingSpot for medium vehicles
class RegularSpot : public ParkingSpot {
private:
    int spotNumber;
    shared_ptr<Vehicle> vehicle;

public:
    explicit RegularSpot(int number) : spotNumber(number), vehicle(nullptr) {}

    bool isAvailable() const override {
        return vehicle == nullptr;
    }

    VehicleSize getSize() const override {
        return VehicleSize::MEDIUM;
    }

    void occupy(shared_ptr<Vehicle> vehicle) override {
        if (isAvailable()) {
            this->vehicle = vehicle;
        } else {
            throw runtime_error("Cannot occupy regular spot: spot already occupied.");
        }
    }

    void vacate() override {
        vehicle = nullptr;
    }

    int getSpotNumber() const override {
        return spotNumber;
    }
};