#include <pddef.h>
using namespace std;

// Given the distinct and valid birthdates of n people as triples (DD, MM, YYYY), order
// them first by ascending birth months (MM), then by ascending birth dates (DD), and
// finally by ascending age.
//
// Given list of birthdays:
// (13, 11, 1983), (24, 5, 1980), (24, 5, 1982), (15, 11, 1983)
void sort_birthdays() {
    vector<iii> birthdays;
    birthdays.emplace_back(13, 11, 1983);
    birthdays.emplace_back(24, 5, 1980);
    birthdays.emplace_back(24, 5, 1982);
    birthdays.emplace_back(15, 11, 1983);

    // Sort the birthdays using a custom comparator
    sort(birthdays.begin(), birthdays.end(), [](const iii &a, const iii &b) {
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);   // Compare by month (MM)
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);   // Compare by day (DD)
        return get<2>(a) > get<2>(b);                               // Compare by year (YYYY)
    });

    // Print sorted birthdays
    for (const auto &b : birthdays) {
        cout << "(" << get<0>(b) << ", " << get<1>(b) << ", " << get<2>(b) << ")" << endl;
    }
}

int main() {
    sort_birthdays();    
    return 0;
}