#include "moviebook.h"
using namespace std;

class ScreeningManager {
public:
    void addScreening(shared_ptr<Screening> screening) {
        string movieTitle = screening->getMovie()->getTitle();
        screeningsByMovieTitle[movieTitle].push_back(screening);
    }

    vector<shared_ptr<Screening>> getScreeningsByMovieTitle(const string& title) {
        if (screeningsByMovieTitle.find(title) != screeningsByMovieTitle.end()) {
            return screeningsByMovieTitle[title];
        }
        return {};
    }

    void addTicket(shared_ptr<Ticket> ticket) {
        string screeningID = ticket->getScreening()->getScreeningID();
        ticketsByScreeningID[screeningID].push_back(ticket);
    }

    vector<shared_ptr<Ticket>> getTicketsByScreeningID(const string& screeningID) {
        if (ticketsByScreeningID.find(screeningID) != ticketsByScreeningID.end()) {
            return ticketsByScreeningID[screeningID];
        }
        return {};
    }

    // Get available seats for a screening
    vector<shared_ptr<Seat>> getAvailableSeats(shared_ptr<Screening> screening) {
        vector<shared_ptr<Seat>> availableSeats;
        auto allSeats = screening->getRoom()->getLayout()->getAllSeats();
        auto bookedTickets = getTicketsByScreeningID(screening->getScreeningID());
        unordered_set<string> bookedSeatNumbers;
        for (const auto& ticket : bookedTickets) {
            bookedSeatNumbers.insert(ticket->getSeat()->getSeatNumber());
        }
        for (const auto& seat : allSeats) {
            if (bookedSeatNumbers.find(seat->getSeatNumber()) == bookedSeatNumbers.end()) {
                availableSeats.push_back(seat);
            }
        }
        return availableSeats;
    }

private:
    unordered_map<string, vector<shared_ptr<Screening>>> screeningsByMovieTitle;
    unordered_map<string, vector<shared_ptr<Ticket>>> ticketsByScreeningID;
};