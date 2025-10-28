#include "unixfilesearch.h"
using namespace std;

// Abscratct base class for composite predicates
class CompositePredicate : public Predicate {
public:
    virtual ~CompositePredicate() = default;
};

// AND composite predicate
class AndPredicate : public CompositePredicate {
private:
    vector<shared_ptr<Predicate>> predicates;
public:
    AndPredicate(const vector<shared_ptr<Predicate>>& preds) : predicates(preds) {}
    bool isMatch(const shared_ptr<File>& file) const override {
        for (const auto& pred : predicates) {
            if (!pred->isMatch(file)) {
                return false;
            }
        }
        return true;
    }
};

// OR composite predicate
class OrPredicate : public CompositePredicate {
private:
    vector<shared_ptr<Predicate>> predicates;
public:
    OrPredicate(const vector<shared_ptr<Predicate>>& preds) : predicates(preds) {}
    bool isMatch(const shared_ptr<File>& file) const override {
        for (const auto& pred : predicates) {
            if (pred->isMatch(file)) {
                return true;
            }
        }
        return false;
    }
};

// NOT composite predicate
class NotPredicate : public CompositePredicate {
private:
    shared_ptr<Predicate> predicate;
public:
    NotPredicate(const shared_ptr<Predicate>& pred) : predicate(pred) {}
    bool isMatch(const shared_ptr<File>& file) const override {
        return !predicate->isMatch(file);
    }
};