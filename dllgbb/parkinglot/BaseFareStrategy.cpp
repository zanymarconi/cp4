#include "parkinglot.h"

// Concrete implementation of FareStrategy for base fare calculation
class BaseFareStrategy : public FareStrategy {
private:
    static constexpr double SMALL_VEHICLE_FARE_RATE = 1.0;
    static constexpr double MEDIUM_VEHICLE_FARE_RATE = 2.0;
    static constexpr double LARGE_VEHICLE_FARE_RATE = 3.0;

public:
    double calculateFare(const Ticket& ticket, double inputFare) const override {
        double fare = inputFare;
        double rate = 0.0;
        VehicleSize size = ticket.getVehicle()->getSize();
        switch (size) {
            case VehicleSize::SMALL:
                rate = SMALL_VEHICLE_FARE_RATE;
                break;
            case VehicleSize::MEDIUM:
                rate = MEDIUM_VEHICLE_FARE_RATE;
                break;
            case VehicleSize::LARGE:
                rate = LARGE_VEHICLE_FARE_RATE;
                break;
            default:
                throw std::invalid_argument("Unknown vehicle size");
        }
        fare += rate * ticket.calculateParkingDurationMinutes();
        return fare;
    }
};