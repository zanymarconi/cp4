#include "parkinglot.h"

// ==================== Ticket ====================
class Ticket {
private:
    string ticketId;
    shared_ptr<Vehicle> vehicle;
    shared_ptr<ParkingSpot> parkingSpot;
    chrono::system_clock::time_point entryTime;
    optional<chrono::system_clock::time_point> exitTime;

public:
    Ticket(const string& id, const shared_ptr<Vehicle>& veh, const shared_ptr<ParkingSpot>& spot)
        : ticketId(id), vehicle(veh), parkingSpot(spot), entryTime(chrono::system_clock::now()), exitTime(nullopt) {}

    Ticket(const string& id, const shared_ptr<Vehicle>& veh, const shared_ptr<ParkingSpot>& spot,
           chrono::system_clock::time_point entry)
        : ticketId(id), vehicle(veh), parkingSpot(spot), entryTime(entry), exitTime(nullopt) {}

    long long calculateParkingDurationMinutes() const {
        chrono::system_clock::time_point endTime = exitTime.value_or(chrono::system_clock::now());
        chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(endTime - entryTime);
        return ceil(duration.count()/ 60000.0);  // Convert milliseconds to minutes and round up
    }

    string getTicketId() const {
        return ticketId;
    }

    shared_ptr<Vehicle> getVehicle() const {
        return vehicle;
    }

    shared_ptr<ParkingSpot> getParkingSpot() const {
        return parkingSpot;
    }

    chrono::system_clock::time_point getEntryTime() const {
        return entryTime;
    }

    optional<chrono::system_clock::time_point> getExitTime() const {
        return exitTime;
    }

    void setExitTime(chrono::system_clock::time_point time) {
        exitTime = time;
    }
};