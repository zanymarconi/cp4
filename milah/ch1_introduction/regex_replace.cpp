#include <pddef.h>
#include <regex>
using namespace std;

void sample1() {
    string input = "The quick brown fox jumps over the lazy dog.";
    string pattern = "(\\w+)(\\s+)(\\w+)"; // Match a word followed by whitespace and another word
    string replacement = "$3<a>$2<b>$1"; // Replace with the third word, followed by <a>, then the second word, followed by <b>, and finally the first word

    // Create a regex object
    regex re(pattern);

    // Perform regex replacement
    string result = regex_replace(input, re, replacement);

    // Output the result
    cout << "Original: " << input << endl;
    cout << "Modified: " << result << endl;
    // Modified: quick<a> <b>The fox<a> <b>brown over<a> <b>jumps lazy<a> <b>the dog.
}

// Let’s define a ‘special word’ as a lowercase alphabet followed by two consecutive digits.
// Given a string, replace all ‘special words’ of length 3 with 3 stars “***”, e.g.,
// S = “line: a70 and z72 will be replaced, aa24 and a872 will not”
// should be transformed into:
// S = “line: *** and *** will be replaced, aa24 and a872 will not”.
void sample2() {
    string input = "line: a70 and z72 will be replaced, aa24 and a872 will not";
    string pattern = "(\\b[a-z]\\d{2}\\b)"; // Match a lowercase letter followed by exactly two digits
    string replacement = "***";

    // Create a regex object
    regex re(pattern);

    // Perform regex replacement
    string result = regex_replace(input, re, replacement);

    // Output the result
    cout << "Original: " << input << endl;
    cout << "Modified: " << result << endl;
    // Modified: line: *** and *** will be replaced, aa24 and a872 will not
}

int main() {
    sample1();
    sample2();
    return 0;
}
