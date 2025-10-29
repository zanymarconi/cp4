#include "tennis_bookings.h"
using namespace std;

Court::Court(int id, vector<int> bookingIds) : 
    courtId(id), bookingIds(bookingIds) {}

// Getters & Setters
