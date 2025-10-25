#include "parkinglot.h"

// ==================== ParkingSpot Interface ====================
class ParkingSpot {
public:
    virtual ~ParkingSpot() {}
    virtual bool isAvailable() const = 0; // Pure virtual function to check availability
    virtual VehicleSize getSize() const = 0; // Pure virtual function to get spot size
    virtual void occupy(shared_ptr<Vehicle> vehicle) = 0; // Pure virtual function to occupy the spot
    virtual void vacate() = 0; // Pure virtual function to vacate the spot
    virtual int getSpotNumber() const = 0; // Pure virtual function to get spot number
};
