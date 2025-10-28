#include "unixfilesearch.h"
using namespace std;

class FileSearchCriteria {
private:
    shared_ptr<Predicate> rootPredicate;
public:
    FileSearchCriteria(const shared_ptr<Predicate>& predicate) : rootPredicate(predicate) {}
    bool matches(const shared_ptr<File>& file) const {
        return rootPredicate->isMatch(file);
    }
};