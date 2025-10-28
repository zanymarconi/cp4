#include "unixfilesearch.h"
using namespace std;

template<typename T>
class ComparisonOperator {
public:
    virtual bool isMatch(const T& actual, const T& expected) const = 0;
    virtual ~ComparisonOperator() = default;
};

template<typename T>
class EqualsOperator : public ComparisonOperator<T> {
public:
    bool isMatch(const T& actual, const T& expected) const override {
        return actual == expected;
    }
};

template<typename T>
class GreaterThanOperator : public ComparisonOperator<T> {
public:
    bool isMatch(const T& actual, const T& expected) const override {
        return actual > expected;
    }
};

template<typename T>
class LessThanOperator : public ComparisonOperator<T> {
public:
    bool isMatch(const T& actual, const T& expected) const override {
        return actual < expected;
    }
};  

template<typename T>
class RegexMatchOperator : public ComparisonOperator<T> {
public:
    bool isMatch(const T& actual, const T& expected) const override {
        try {
            return regex_match(actual, regex(expected));
        } catch (const regex_error&) {
            return false;
        }
    }
};



