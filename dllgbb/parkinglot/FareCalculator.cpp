#include "parkinglot.h"

class FareCalculator {
private:
    vector<shared_ptr<FareStrategy>> fareStrategies;
public:
    explicit FareCalculator(const vector<shared_ptr<FareStrategy>>& strategies)
        : fareStrategies(move(strategies)) {}

    double calculateTotalFare(const Ticket& ticket) const {
        double totalFare = 0.0;
        for (const auto& strategy : fareStrategies) {
            double fare = strategy->calculateFare(ticket, totalFare);
            totalFare += fare;
        }
        return totalFare;
    }
};