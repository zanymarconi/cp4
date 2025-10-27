#include "moviebook.h"
using namespace std;

class Layout {
public:
    explicit Layout(const string& layoutName, int rows) : layoutName(layoutName) {
        seats.assign(rows, vector<shared_ptr<Seat>>());
    }

    shared_ptr<Seat> getSeatByPosition(int row, int col) const {
        if (row >= 0 && row < seats.size() && col >= 0 && col < seats[row].size()) {
            return seats[row][col];
        }
        return nullptr; // Seat not found
    }

    void addSeatInRow(int row, shared_ptr<Seat> seat) {
        if (row >= 0 && row < seats.size()) {
            seats[row].push_back(seat);
        }
    }

    // Get all seats in the layout
    vector<shared_ptr<Seat>> getAllSeats() const {
        vector<shared_ptr<Seat>> allSeats;
        for (const auto& row : seats) {
            for (const auto& seat : row) {
                allSeats.push_back(seat);
            }
        }
        return allSeats;
    }

    // Get seats object constant reference
    const vector<vector<shared_ptr<Seat>>>& getSeats() const {
        return seats;
    }

private:
    string layoutName;
    vector<vector<shared_ptr<Seat>>> seats; // Dynamic 2D grid of seats
};