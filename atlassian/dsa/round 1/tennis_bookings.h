#ifndef TENNIS_BOOKINGS
#define TENNIS_BOOKINGS

#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that given a list of tennis court bookings with start and finish times, returns a plan assigning each booking to a specific court, 
ensuring each court is used by only one booking at a time and using the minimum amount of courts with unlimited number of courts available.
An example of the booking record might look like:

class BookingRecord:
  id: int // ID of the booking.
  start_time: int
  finish_time: int
and our function is going to look like:

List<Court> assignCourts(List<BookingRecord> bookingRecords


class Court:
  courtId
  List<int> bookingRecordIds // ID for Non-Overlapping Booking Record, Sorted as per start_time
*/

class Court {
public:
  Court(int id, vector<int> bookingIds);
private:
  int courtId;
  vector<int> bookingIds;
};

class BookingRecord {
public:
  BookingRecord(int id, int start, int end);
  int getStartTime();
  int getFinishTime();
  int getBookingId();
private:
  int bookingId;
  int startTime; // TODO: consider epoch millis
  int finishTime;
};

class TennisBooking {
public:
  vector<Court> assignCourts(const vector<BookingRecord>& bookingRecords);
};

#endif