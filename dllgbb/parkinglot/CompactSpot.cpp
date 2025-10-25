#include "parkinglot.h"

// Concrete implementation of ParkingSpot for compact vehicles
class CompactSpot : public ParkingSpot {
private:
    int spotNumber;
    shared_ptr<Vehicle> vechicle;

public:
    explicit CompactSpot(int number) : spotNumber(number), vechicle(nullptr) {}

    bool isAvailable() const override {
        return vechicle == nullptr;
    }

    VehicleSize getSize() const override {
        return VehicleSize::SMALL;
    }

    void occupy(shared_ptr<Vehicle> vehicle) override {
        if (isAvailable()) {
            this->vechicle = vehicle;
        } else {
            throw runtime_error("Cannot occupy compact spot: spot already occupied.");
        }
    }

    void vacate() override {
        vechicle = nullptr;
    }

    int getSpotNumber() const override {
        return spotNumber;
    }
};
