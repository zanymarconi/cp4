#include "unixfilesearch.h"
using namespace std;

template<typename T>
class SimplePredicate : public Predicate {
public:
    SimplePredicate(AttributeType attrType,
                    shared_ptr<ComparisonOperator<T>> compOp,
                    const T& expectedVal)
        : attributeType(attrType), compOperator(compOp), expectedValue(expectedVal) {}

    bool isMatch(const shared_ptr<File>& file) const override {
        AttributeValueType actualValue = file->extract(attributeType);
        // Match attributValueType and T is same
        if (holds_alternative<T>(actualValue)) {
            T actual = get<T>(actualValue);
            return compOperator->isMatch(actual, expectedValue);
        }
        return false;
    }
private:
    AttributeType attributeType;
    shared_ptr<ComparisonOperator<T>> compOperator;
    T expectedValue;
};