#include "parkinglot.h"

// ==================== FareStrategy Interface ====================
class FareStrategy {
public:
    virtual ~FareStrategy() = default;
    virtual double calculateFare(const Ticket& ticket, double inputFare) const = 0;
};