#include "parkinglot.h"

// Concrete implementation of FareStrategy for peak hours fare calculation
class PeakHoursFareStrategy : public FareStrategy {
private:
    static constexpr double PEAK_HOUR_SURCHARGE_RATE = 1.5; // 50% surcharge during peak hours

    bool isPeakHours(chrono::system_clock::time_point entryTime) const {
        time_t timeT = chrono::system_clock::to_time_t(entryTime);
        tm localTime = *localtime(&timeT);
        int hour = localTime.tm_hour;
        return (hour >= 7 && hour < 10) || (hour >= 16 && hour < 19);
    }

public:
    double calculateFare(const Ticket& ticket, double inputFare) const override {
        double fare = inputFare;
        if (isPeakHours(ticket.getEntryTime())) {
            fare *= PEAK_HOUR_SURCHARGE_RATE;
        }
        return fare;
    }
};