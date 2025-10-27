#include "moviebook.h"
using namespace std;

class Movie {
public:
    Movie(const string& title, int durationInMinutes)
        : title(title), durationInMinutes(durationInMinutes) {}

    string getTitle() const {
        return title;
    }

    int getDuration() const {
        return durationInMinutes;
    }

private: 
    string title;
    int durationInMinutes;
};