#include "moviebook.h"
using namespace std;

class Order {
public:
    Order(long long orderTimeInMillis) : orderTimeInMillis(orderTimeInMillis) {}

    void addTicket(shared_ptr<Ticket> ticket) {
        tickets.push_back(ticket);
    }

    double getTotalPrice() const {
        double total = 0.0;
        for (const auto& ticket : tickets) {
            total += ticket->getPrice();
        }
        return total;
    }

    const vector<shared_ptr<Ticket>>& getTickets() const {
        return tickets;
    }
private:
    vector<shared_ptr<Ticket>> tickets;
    long long orderTimeInMillis; // Epoch time representation
};