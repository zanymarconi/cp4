#include "moviebook.h"
using namespace std;

class Seat {
public:
    explicit Seat(const string& seatNumber, shared_ptr<PricingStrategy> pricingStrategy)
        : seatNumber(seatNumber), pricingStrategy(move(pricingStrategy)) {}

    explicit Seat(const string& seatNumber)
        : seatNumber(seatNumber), pricingStrategy(nullptr) {}

    double getPrice() const {
        return pricingStrategy->getPrice();
    }

    string getSeatNumber() const {
        return seatNumber;
    }

    void setPricingStrategy(shared_ptr<PricingStrategy> newStrategy) {
        pricingStrategy = move(newStrategy);
    }

    bool operator==(const Seat& other) const {
        return seatNumber == other.seatNumber;
    }

private:
    string seatNumber;
    shared_ptr<PricingStrategy> pricingStrategy;
};