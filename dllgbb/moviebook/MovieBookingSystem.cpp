#include "moviebook.h"
using namespace std;

class MovieBookingSystem {
public:

    MovieBookingSystem() : screeningManager(make_unique<ScreeningManager>()) {}

    // Book a ticket for a specific screening and seat
    shared_ptr<Ticket> bookTicket(shared_ptr<Screening> screening, shared_ptr<Seat> seat) {
        // Optimistic locking 
        lock_guard<mutex> lock(bookMutex);

        // Check if the seat is available
        auto availableSeats = getAvailableSeats(screening);
        auto it = find_if(availableSeats.begin(), availableSeats.end(),
                          [&seat](const shared_ptr<Seat>& s) { 
                            return s->getSeatNumber() == seat->getSeatNumber();
                          });
        if (it == availableSeats.end()) {
            throw runtime_error("Seat is already booked.");
        }  
        // Create a new ticket
        shared_ptr<Ticket> ticket = make_shared<Ticket>(screening, seat, seat->getPrice());
        // Add the ticket to the screening manager
        screeningManager->addTicket(ticket);
        return ticket;
    }

    // Get available seats for a screening
    vector<shared_ptr<Seat>> getAvailableSeats(shared_ptr<Screening> screening) {
        return screeningManager->getAvailableSeats(screening);
    }

    // Get screenings by movie title
    vector<shared_ptr<Screening>> getScreeningsByMovieTitle(const string& title) {
        return screeningManager->getScreeningsByMovieTitle(title);
    }
    // Get all tickets for a screening
    vector<shared_ptr<Ticket>> getTicketsForScreening(shared_ptr<Screening> screening) {
        return screeningManager->getTicketsByScreeningID(screening->getScreeningID());
    }

    // Add screening for a movie
    void addScreening(shared_ptr<Screening> screening) {
        screeningManager->addScreening(screening);
    }

    void addMovie(shared_ptr<Movie> movie) {
        movies.push_back(movie);
    }

    vector<shared_ptr<Movie>> getMovies() const {
        return movies;
    }

    void addCinema(shared_ptr<Cinema> cinema) {
        cinemas.push_back(cinema);
    }

    vector<shared_ptr<Cinema>> getCinemas() const {
        return cinemas;
    }

private:
    vector<shared_ptr<Movie>> movies;
    vector<shared_ptr<Cinema>> cinemas;
    unique_ptr<ScreeningManager> screeningManager;

    mutable mutex bookMutex;
};