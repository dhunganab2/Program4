
#include "OrderedSet.h"

// **Friend function for OrderedSet Difference**
OrderedSet operator-(OrderedSet &left, OrderedSet &right) {
    // Calls the global `operator-` for mySet
    mySet ms = operator-(static_cast<mySet&>(left), static_cast<mySet&>(right));

    // Convert `mySet` result to `OrderedSet` and ensure it's sorted
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}

// **Overloaded `<<` operator for OrderedSet**
ostream& operator<<(ostream &ost, OrderedSet &OS) {
    if (OS.isempty()) {
        ost << "Ordered Set is EMPTY";
        return ost;
    }
    ost << "{ ";
    int count = 0;
    for (size_t i = 0; i < OS.getelts().size(); i++) {
        ost << OS.getelts()[i];
        count++;
        if (i != OS.getelts().size() - 1) {
            ost << " ,";
            if (count == 10) {
                ost << "\n";
                count = 0;
            }
        }
    }
    ost << " }";
    return ost;
}
