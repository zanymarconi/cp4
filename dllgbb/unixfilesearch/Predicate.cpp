#include "unixfilesearch.h"
using namespace std;

class Predicate {
public:
    virtual ~Predicate() = default;
    virtual bool isMatch(const shared_ptr<File>& file) const = 0;
};