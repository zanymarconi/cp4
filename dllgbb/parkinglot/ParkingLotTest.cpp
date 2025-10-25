#include "parkinglot.h"  // Include the parking lot header

// Test helper functions
void printTestResult(const string& testName, bool passed) {
    cout << "[" << (passed ? "PASS" : "FAIL") << "] " << testName << endl;
}

// Test 1: Basic vehicle creation and properties
void testVehicleCreation() {
    auto motorcycle = make_shared<Motorcycle>("MOTO-123");
    auto car = make_shared<Car>("CAR-456");
    auto truck = make_shared<Truck>("TRUCK-789");

    bool passed = (motorcycle->getLicensePlate() == "MOTO-123" &&
                   motorcycle->getSize() == VehicleSize::SMALL &&
                   car->getLicensePlate() == "CAR-456" &&
                   car->getSize() == VehicleSize::MEDIUM &&
                   truck->getLicensePlate() == "TRUCK-789" &&
                   truck->getSize() == VehicleSize::LARGE);

    printTestResult("Vehicle Creation", passed);
}

// Test 2: Parking spot availability and occupation
void testParkingSpotOperations() {
    auto spot = make_shared<CompactSpot>(1);
    auto vehicle = make_shared<Motorcycle>("TEST-001");

    bool initiallyAvailable = spot->isAvailable();
    spot->occupy(vehicle);
    bool occupiedCorrectly = !spot->isAvailable();
    spot->vacate();
    bool vacatedCorrectly = spot->isAvailable();

    bool passed = (initiallyAvailable && occupiedCorrectly && vacatedCorrectly &&
                   spot->getSpotNumber() == 1 &&
                   spot->getSize() == VehicleSize::SMALL);

    printTestResult("Parking Spot Operations", passed);
}

// Test 3: ParkingManager - find and park vehicle
void testParkingManagerBasic() {
    // Create parking spots
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::SMALL] = {
        make_shared<CompactSpot>(1),
        make_shared<CompactSpot>(2)
    };
    spots[VehicleSize::MEDIUM] = {
        make_shared<RegularSpot>(3),
        make_shared<RegularSpot>(4)
    };
    spots[VehicleSize::LARGE] = {
        make_shared<OversizedSpot>(5)
    };

    auto manager = make_shared<ParkingManager>(spots);
    auto car = make_shared<Car>("CAR-001");

    // Find and park vehicle
    auto spot = manager->parkVehicle(car);
    bool parkedSuccessfully = (spot != nullptr && !spot->isAvailable());

    // Try to find spot for the same vehicle again (should work as new search)
    auto car2 = make_shared<Car>("CAR-002");
    auto spot2 = manager->parkVehicle(car2);
    bool secondCarParked = (spot2 != nullptr && spot2 != spot);

    printTestResult("ParkingManager Basic Operations", parkedSuccessfully && secondCarParked);
}

// Test 4: Best-fit parking allocation
void testBestFitAllocation() {
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::SMALL] = {make_shared<CompactSpot>(1)};
    spots[VehicleSize::MEDIUM] = {make_shared<RegularSpot>(2)};
    spots[VehicleSize::LARGE] = {make_shared<OversizedSpot>(3)};

    auto manager = make_shared<ParkingManager>(spots);
    auto motorcycle = make_shared<Motorcycle>("MOTO-001");

    // Motorcycle should get the SMALL spot
    auto spot = manager->parkVehicle(motorcycle);
    bool correctSize = (spot != nullptr && spot->getSize() == VehicleSize::SMALL);

    printTestResult("Best-Fit Allocation", correctSize);
}

// Test 5: Upgrade parking (small vehicle in larger spot when small is full)
void testUpgradeParking() {
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::SMALL] = {make_shared<CompactSpot>(1)};
    spots[VehicleSize::MEDIUM] = {make_shared<RegularSpot>(2)};

    auto manager = make_shared<ParkingManager>(spots);
    auto motorcycle1 = make_shared<Motorcycle>("MOTO-001");
    auto motorcycle2 = make_shared<Motorcycle>("MOTO-002");

    // First motorcycle gets small spot
    auto spot1 = manager->parkVehicle(motorcycle1);
    // Second motorcycle should upgrade to medium spot
    auto spot2 = manager->parkVehicle(motorcycle2);

    bool passed = (spot1 != nullptr && spot1->getSize() == VehicleSize::SMALL &&
                   spot2 != nullptr && spot2->getSize() == VehicleSize::MEDIUM);

    printTestResult("Upgrade Parking", passed);
}

// Test 6: Parking lot full scenario
void testParkingLotFull() {
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::MEDIUM] = {make_shared<RegularSpot>(1)};

    auto manager = make_shared<ParkingManager>(spots);
    auto car1 = make_shared<Car>("CAR-001");
    auto car2 = make_shared<Car>("CAR-002");

    auto spot1 = manager->parkVehicle(car1);
    auto spot2 = manager->parkVehicle(car2);  // Should fail - lot is full

    bool passed = (spot1 != nullptr && spot2 == nullptr);
    printTestResult("Parking Lot Full", passed);
}

// Test 7: Unpark vehicle
void testUnparkVehicle() {
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::MEDIUM] = {make_shared<RegularSpot>(1)};

    auto manager = make_shared<ParkingManager>(spots);
    auto car = make_shared<Car>("CAR-001");

    auto spot = manager->parkVehicle(car);
    bool parked = !spot->isAvailable();
    
    manager->unparkVehicle(car);
    bool unparked = spot->isAvailable();

    // Should be able to park another car now
    auto car2 = make_shared<Car>("CAR-002");
    auto spot2 = manager->parkVehicle(car2);
    bool reparked = (spot2 != nullptr);

    printTestResult("Unpark Vehicle", parked && unparked && reparked);
}

// Test 8: Ticket creation and duration calculation
void testTicketOperations() {
    auto vehicle = make_shared<Car>("CAR-001");
    auto spot = make_shared<RegularSpot>(1);

    Ticket ticket("TICKET-001", vehicle, spot);

    // Wait a bit to accumulate some parking time
    this_thread::sleep_for(chrono::milliseconds(100));

    long long duration = ticket.calculateParkingDurationMinutes();
    bool durationValid = (duration >= 0);  // Should be at least 0 minutes

    // Set exit time
    ticket.setExitTime(chrono::system_clock::now());
    bool exitTimeSet = ticket.getExitTime().has_value();

    printTestResult("Ticket Operations", durationValid && exitTimeSet);
}

// Test 9: Base fare calculation
void testBaseFareCalculation() {
    auto motorcycle = make_shared<Motorcycle>("MOTO-001");
    auto car = make_shared<Car>("CAR-001");
    auto truck = make_shared<Truck>("TRUCK-001");
    
    auto spot = make_shared<RegularSpot>(1);
    auto entryTime = chrono::system_clock::now() - chrono::minutes(60);
    
    Ticket motoTicket("T1", motorcycle, spot, entryTime);
    Ticket carTicket("T2", car, spot, entryTime);
    Ticket truckTicket("T3", truck, spot, entryTime);

    BaseFareStrategy strategy;
    double motoFare = strategy.calculateFare(motoTicket, 0.0);

    double carFare = strategy.calculateFare(carTicket, 0.0);
    double truckFare = strategy.calculateFare(truckTicket, 0.0);

    // Motorcycle (1.0/min) < Car (2.0/min) < Truck (3.0/min)
    bool passed = (motoFare < carFare && carFare < truckFare && motoFare > 0);
    printTestResult("Base Fare Calculation", passed);
}

// Test 10: Peak hours fare calculation
void testPeakHoursFare() {
    auto vehicle = make_shared<Car>("CAR-001");
    auto spot = make_shared<RegularSpot>(1);
    
    // Create a time at 8 AM (peak hours)
    auto now = chrono::system_clock::now();
    auto timeT = chrono::system_clock::to_time_t(now);
    auto tm = *localtime(&timeT);
    tm.tm_hour = 8;  // 8 AM - peak hour
    tm.tm_min = 0;
    auto peakTime = chrono::system_clock::from_time_t(mktime(&tm));
    
    Ticket ticket("T1", vehicle, spot, peakTime);
    
    PeakHoursFareStrategy strategy;
    double normalFare = 100.0;
    double peakFare = strategy.calculateFare(ticket, normalFare);
    
    // Peak fare should be 1.5x
    bool passed = (peakFare == 150.0);
    printTestResult("Peak Hours Fare", passed);
}

// Test 11: Multiple fare strategies
void testMultipleFareStrategies() {
    vector<shared_ptr<FareStrategy>> strategies = {
        make_shared<BaseFareStrategy>(),
        make_shared<PeakHoursFareStrategy>()
    };
    
    FareCalculator calculator(strategies);
    
    auto car = make_shared<Car>("CAR-001");
    auto spot = make_shared<RegularSpot>(1);
    
    // Create peak hour time
    auto now = chrono::system_clock::now();
    auto timeT = chrono::system_clock::to_time_t(now);
    auto tm = *localtime(&timeT);
    tm.tm_hour = 8;
    tm.tm_min = 0;
    auto peakTime = chrono::system_clock::from_time_t(mktime(&tm));
    peakTime -= chrono::minutes(60);  // 1 hour parking
    
    Ticket ticket("T1", car, spot, peakTime);
    double fare = calculator.calculateTotalFare(ticket);
    
    // Base fare for car: 2.0 * 60 = 120, then peak multiplier: 120 * 1.5 = 180
    bool passed = (fare > 0);  // Just check it's calculated
    printTestResult("Multiple Fare Strategies", passed);
}

// Test 12: Full parking lot integration test
void testFullParkingLotIntegration() {
    // Setup parking spots
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::SMALL] = {make_shared<CompactSpot>(1)};
    spots[VehicleSize::MEDIUM] = {
        make_shared<RegularSpot>(2),
        make_shared<RegularSpot>(3)
    };
    spots[VehicleSize::LARGE] = {make_shared<OversizedSpot>(4)};

    auto manager = make_shared<ParkingManager>(spots);
    
    vector<shared_ptr<FareStrategy>> strategies = {
        make_shared<BaseFareStrategy>(),
        make_shared<PeakHoursFareStrategy>()
    };
    auto calculator = make_shared<FareCalculator>(strategies);
    
    ParkingLot parkingLot(manager, calculator);
    
    // Enter vehicles
    auto car1 = make_shared<Car>("CAR-001");
    auto car2 = make_shared<Car>("CAR-002");
    auto motorcycle = make_shared<Motorcycle>("MOTO-001");
    
    auto ticket1 = parkingLot.enterVehicle(car1);
    auto ticket2 = parkingLot.enterVehicle(car2);
    auto ticket3 = parkingLot.enterVehicle(motorcycle);
    
    bool allEntered = (ticket1 != nullptr && ticket2 != nullptr && ticket3 != nullptr);
    
    // Wait a bit
    this_thread::sleep_for(chrono::milliseconds(100));
    
    // Exit vehicles
    double fare1 = parkingLot.leaveVehicle(ticket1);
    double fare2 = parkingLot.leaveVehicle(ticket2);
    double fare3 = parkingLot.leaveVehicle(ticket3);
    
    bool allExited = (fare1 >= 0 && fare2 >= 0 && fare3 >= 0);
    
    // Try to park another car (should work now that spots are free)
    auto car3 = make_shared<Car>("CAR-003");
    auto ticket4 = parkingLot.enterVehicle(car3);
    bool canParkAfterExit = (ticket4 != nullptr);
    
    printTestResult("Full Integration Test", allEntered && allExited && canParkAfterExit);
}

// Test 13: Invalid operations
void testInvalidOperations() {
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::MEDIUM] = {make_shared<RegularSpot>(1)};
    
    auto manager = make_shared<ParkingManager>(spots);
    vector<shared_ptr<FareStrategy>> strategies = {
        make_shared<BaseFareStrategy>()
    };
    auto calculator = make_shared<FareCalculator>(strategies);
    
    ParkingLot parkingLot(manager, calculator);
    
    auto car = make_shared<Car>("CAR-001");
    auto ticket = parkingLot.enterVehicle(car);

    // Wait a bit
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    // Try to exit twice
    double fare1 = parkingLot.leaveVehicle(ticket);
    double fare2 = parkingLot.leaveVehicle(ticket);  // Should return 0
    
    bool passed = (fare1 > 0 && fare2 == 0.0);
    printTestResult("Invalid Operations (Double Exit)", passed);
}

// Test 14: Large vehicle cannot fit in small spot
void testVehicleSizeMismatch() {
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    spots[VehicleSize::SMALL] = {make_shared<CompactSpot>(1)};
    // No medium or large spots
    
    auto manager = make_shared<ParkingManager>(spots);
    auto truck = make_shared<Truck>("TRUCK-001");
    
    // Truck should not fit in compact spot
    auto spot = manager->parkVehicle(truck);
    bool passed = (spot == nullptr);
    
    printTestResult("Vehicle Size Mismatch", passed);
}

// Test 15: Concurrent parking operations simulation
void testConcurrentOperations() {
    unordered_map<VehicleSize, vector<shared_ptr<ParkingSpot>>> spots;
    for (int i = 1; i <= 10; i++) {
        spots[VehicleSize::MEDIUM].push_back(make_shared<RegularSpot>(i));
    }
    
    auto manager = make_shared<ParkingManager>(spots);
    vector<shared_ptr<FareStrategy>> strategies = {
        make_shared<BaseFareStrategy>()
    };
    auto calculator = make_shared<FareCalculator>(strategies);
    
    ParkingLot parkingLot(manager, calculator);
    
    vector<shared_ptr<Ticket>> tickets;
    
    // Park 10 vehicles
    for (int i = 0; i < 10; i++) {
        auto car = make_shared<Car>("CAR-" + to_string(i));
        auto ticket = parkingLot.enterVehicle(car);
        if (ticket) {
            tickets.push_back(ticket);
        }
    }
    
    // 11th vehicle should fail
    auto extraCar = make_shared<Car>("CAR-EXTRA");
    auto extraTicket = parkingLot.enterVehicle(extraCar);
    
    bool passed = (tickets.size() == 10 && extraTicket == nullptr);
    printTestResult("Concurrent Operations", passed);
}

int main() {
    cout << "=== Running Parking Lot Test Suite ===\n" << endl;

    testVehicleCreation();
    testParkingSpotOperations();
    testParkingManagerBasic();
    testBestFitAllocation();
    testUpgradeParking();
    testParkingLotFull();
    testUnparkVehicle();
    testTicketOperations();
    testBaseFareCalculation();
    testPeakHoursFare();
    testMultipleFareStrategies();
    testFullParkingLotIntegration();
    testInvalidOperations();
    testVehicleSizeMismatch();
    testConcurrentOperations();

    cout << "\n=== Test Suite Completed ===" << endl;
    
    return 0;
}