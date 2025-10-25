#include "parkinglot.h"

// ==================== ParkingLot (Facade) ====================
class ParkingLot {
private:
    shared_ptr<ParkingManager> parkingManager;
    shared_ptr<FareCalculator> fareCalculator;
    mutable int ticketCounter = 0;

    string generateTicketId() const {
        return "TICKET-" + to_string(++ticketCounter);
    }

public:
    ParkingLot(shared_ptr<ParkingManager> manager, shared_ptr<FareCalculator> calculator)
        : parkingManager(manager), fareCalculator(calculator) {}

    shared_ptr<Ticket> enterVehicle(shared_ptr<Vehicle> vehicle) {
        shared_ptr<ParkingSpot> spot = parkingManager->parkVehicle(vehicle);
        if (!spot) {
            return nullptr;  // No available spot
        }
        return make_shared<Ticket>(Ticket(generateTicketId(), vehicle, spot));
    }

    double leaveVehicle(shared_ptr<Ticket> ticket) {
        double fare = 0.0;
        if (ticket && !ticket->getExitTime().has_value()) {
            ticket->setExitTime(chrono::system_clock::now());
            parkingManager->unparkVehicle(ticket->getVehicle());
            fare += fareCalculator->calculateTotalFare(*ticket);
        }
        return fare;
    }
};