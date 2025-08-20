#ifndef PDDEF_H
#define PDDEF_H

#include <limits>
#include <cmath>

// Common data type definitions
typedef long long ll; 
typedef tuple<int, int, int> tiii;                          // Tuple of three integers

// Shortcuts for common constants
const int _INF = std::numeric_limits<int>::max();           // is 2^31 - 1 for 32-bits wide
const int _MINF = std::numeric_limits<int>::min();          // is -2^31
const ll _LLINF = std::numeric_limits<ll>::max();           // is 2^63 - 1 for 64-bits wide∂
const ll _LLMINF = std::numeric_limits<ll>::min();          // is -2^63
const double _EPS = std::numeric_limits<double>::epsilon(); // is 2^52 which is approx 2.22e-16

// Constants for mathematical operations
const double _PI = M_PI;                                    // Pi constant

#endif