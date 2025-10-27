#include "moviebook.h"
using namespace std;

class Ticket {
public:
    Ticket(shared_ptr<Screening> screening, shared_ptr<Seat> seat, double price)
        : screening(screening), seat(seat), price(price) {}

    shared_ptr<Screening> getScreening() const {
        return screening;
    }

    shared_ptr<Seat> getSeat() const {
        return seat;
    }

    double getPrice() const {
        return price;
    }

private:
    shared_ptr<Screening> screening;
    shared_ptr<Seat> seat;
    double price;
};