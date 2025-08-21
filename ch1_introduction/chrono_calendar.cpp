#include <chrono>
#include <iostream>

using namespace std;

/*
    Sample Output:
    Past date: 2010-08-09
    Today's date: 2025-08-21
    Days elapsed since 2010-08-09: 5491 days
    Weekday of the past date: Mon
*/
void days_elapsed_and_wod(const chrono::year_month_day &past_date) {
    cout << "Past date: " << past_date << endl;

    chrono::year_month_day today = chrono::year_month_day{chrono::floor<chrono::days>(chrono::system_clock::now())};
    cout << "Today's date: " << today << endl;

    // Calculate the number of days elapsed since the past date
    chrono::days days_elapsed = chrono::sys_days(today) - chrono::sys_days(past_date);
    cout << "Days elapsed since " << past_date << ": " << days_elapsed.count() << " days" << endl;

    // Calculate the weekday of the past date
    chrono::weekday weekday = chrono::weekday{past_date};
    cout << "Weekday of the past date: " << weekday << endl;
}

int main()
{
    // Create a past date (year/month/day format)
    chrono::year_month_day past_date{chrono::year{2010},
                                     chrono::month{8},
                                     chrono::day{9}};
    days_elapsed_and_wod(past_date);
    return 0;
}