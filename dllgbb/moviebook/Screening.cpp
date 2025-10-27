#include "moviebook.h"
using namespace std;

class Screening {
public:
    Screening(string screeningID, shared_ptr<Movie> movie, shared_ptr<Room> room,
              long long startTimeInMillis, long long endTimeInMillis)
        : screeningID(screeningID), movie(movie), room(room),
          startTimeInMillis(startTimeInMillis), endTimeInMillis(endTimeInMillis) {}

    string getScreeningID() const {
        return screeningID;
    }

    shared_ptr<Movie> getMovie() const {
        return movie;
    }

    shared_ptr<Room> getRoom() const {
        return room;
    }

    // Get start timestamp with date and time
    string getStartTime() const {
        time_t start = startTimeInMillis / 1000;
        struct tm* timeinfo = localtime(&start);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        return string(buffer);
    }

    string getEndTime() const {
        time_t end = endTimeInMillis / 1000;
        struct tm* timeinfo = localtime(&end);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        return string(buffer);
    }

private:
    string screeningID;
    shared_ptr<Movie> movie;
    shared_ptr<Room> room;
    long long startTimeInMillis; // Epoch time representation
    long long endTimeInMillis;   // Epoch time representation
};