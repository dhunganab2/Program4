
#include "OrderedSet.h"

// Constructor converting mySet to OrderedSet
OrderedSet::OrderedSet(mySet S) {
    elts = S.getelts();
    size = S.getsize();
    SortSet();
}

// Ensure order when adding elements
bool OrderedSet::addelt(int x) {
    if (mySet::addelt(x)) {
        SortSet();
        return true;
    }
    return false;
}

// Sort the set
void OrderedSet::SortSet() {
    std::sort(elts.begin(), elts.end());
}

// Overloaded Union operator
OrderedSet OrderedSet::operator+(OrderedSet& OS) {
    mySet ms = mySet::operator+(OS);
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}

// Overloaded Intersection operator
OrderedSet OrderedSet::operator*(OrderedSet& OS) {
    mySet ms = mySet::operator*(OS);
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}

// Overloaded Difference operator
OrderedSet operator-(OrderedSet& left, OrderedSet& right) {
    mySet ms = operator-(static_cast<mySet&>(left), static_cast<mySet&>(right));
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& ost, OrderedSet& OS) {
    ost << "{ ";
    for (size_t i = 0; i < OS.elts.size(); i++) {
        ost << OS.elts[i];
        if ((i + 1) % 10 == 0 || i == OS.elts.size() - 1) {
            ost << " \n";
        } else {
            ost << ", ";
        }
    }
    ost << "}";
    return ost;
}
