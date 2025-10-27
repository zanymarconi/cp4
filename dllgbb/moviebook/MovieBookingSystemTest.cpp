#include "moviebook.h"
using namespace std;

class MovieBookingSystemTest : public MovieBookingSystem {
   public:
    void runTests() {
        // Create the booking system
        MovieBookingSystem bookingSystem;

        // Create a movie
        auto movie = std::make_shared<Movie>("Inception", /* durationInMinutes= */ 148);
        bookingSystem.addMovie(movie);
        printf("Created movie: %s\n", movie->getTitle().c_str());

        // Create a cinema with a room
        auto cinema = std::make_shared<Cinema>("CinePlex Downtown");
        auto layout = std::make_shared<Layout>("Basic Layout", 5);  // 5 rows
        auto room = std::make_shared<Room>("Room 1", layout);
        cinema->addRoom(room);
        bookingSystem.addCinema(cinema);
        printf("Created cinema: %s with room: %s\n", cinema->getName().c_str(), room->getRoomName().c_str());

        // Add seats to the layout
        for (int i = 0; i < 5; ++i) {       // 5 rows
            for (int j = 0; j < ((i == 0)? 3: ((i == 1)? 7: 10)); ++j) {  // 3 + 7 + 10*3 = 40 seats
                string seatNumber = to_string(i) + "-" + to_string(j);
                auto seat = std::make_shared<Seat>(seatNumber);
                layout->addSeatInRow(i, seat);
            }
        }
        printf("Added seats to layout: %s\n", layout->getAllSeats().size() > 0 ? "Success" : "Failure");

        // Set pricing strategies for some seats
        auto vipRate = std::make_shared<VIPRate>(25.0);
        auto premiumRate = std::make_shared<PremiumRate>(15.0);
        auto normalRate = std::make_shared<NormalRate>(10.0);

        // Set pricing for back row (VIP)
        for (int j = 0; j < layout->getSeats()[0].size(); ++j) {
            auto seat = layout->getSeatByPosition(0, j);
            if (seat)
                seat->setPricingStrategy(vipRate);
        }

        // Set pricing for premium seats in back row
        for (int j = 0; j < layout->getSeats()[1].size(); ++j) {
            auto seat = layout->getSeatByPosition(1, j);
            if (seat)
                seat->setPricingStrategy(premiumRate);
        }

        // Set pricing for rows (normal)
        for (int i = 2; i < 5; ++i) {
            for (int j = 0; j < layout->getSeats()[i].size(); ++j) {
                auto seat = layout->getSeatByPosition(i, j);
                if (seat)
                    seat->setPricingStrategy(normalRate);
            }
        }

        // Create a screening
        long long currentTime = getCurrentEpochMillis();
        long long oneHourLater = currentTime + (60 * 60 * 1000);         // 1 hour from now
        long long threeHoursLater = currentTime + (3 * 60 * 60 * 1000);  // 3 hours from now

        auto screening = std::make_shared<Screening>("screening 42", movie, room, oneHourLater, threeHoursLater);
        bookingSystem.addScreening(screening);

        // Book some tickets
        printf("Booking tickets...\n");

        auto seat1 = layout->getSeatByPosition(0, 2);  // VIP seat
        auto seat2 = layout->getSeatByPosition(1, 6);  // Premium seat
        auto seat3 = layout->getSeatByPosition(4, 9);  // Normal seat

        bookingSystem.bookTicket(screening, seat1);
        bookingSystem.bookTicket(screening, seat2);
        bookingSystem.bookTicket(screening, seat3);

        printf("Booked 3 tickets.\n");
        int actualTickets = bookingSystem.getTicketsForScreening(screening).size();
        printf("Total tickets sold: %d\n", actualTickets);
        assert(actualTickets == 3);

        // Check available seats
        auto availableSeats = bookingSystem.getAvailableSeats(screening);
        printf("Available seats after booking %d tickets: %zu\n", actualTickets, availableSeats.size());
        assert(availableSeats.size() == (40 - actualTickets));  // 50 total seats - booked tickets

        // Create an order
        auto order = std::make_shared<Order>(getCurrentEpochMillis());
        auto tickets = bookingSystem.getTicketsForScreening(screening);
        for (const auto& ticket : tickets) {
            order->addTicket(ticket);
        }

        printf("Order created with %zu tickets. Total price: $%.2f\n",
               order->getTickets().size(), order->getTotalPrice());
        assert(order->getTickets().size() == 3);
        assert(order->getTotalPrice() == (15.0 + 10.0 + 25.0));  // Premium + Normal + VIP

        printf("All tests passed successfully.\n");
    }

   private:
    long long getCurrentEpochMillis() {
        return static_cast<long long>(std::chrono::duration_cast<std::chrono::milliseconds>(
                                          std::chrono::system_clock::now().time_since_epoch())
                                          .count());
    }
};

int main() {
    MovieBookingSystemTest mbsTest;
    printf("Starting Movie Booking System Tests...\n");
    mbsTest.runTests();
    return 0;
}