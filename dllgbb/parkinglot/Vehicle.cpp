#include "parkinglot.h"

// ==================== Vehicle Interface ====================
class Vehicle {
public:
    virtual ~Vehicle() = default; // Virtual destructor for proper cleanup
    virtual VehicleSize getSize() const = 0; // Pure virtual function to get vehicle size
    virtual string getLicensePlate() const = 0; // Pure virtual function to get license plate
};