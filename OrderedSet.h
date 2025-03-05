#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include "mySet.h"
#include <algorithm>

class OrderedSet : public mySet {
public:
    OrderedSet() = default;

    // Converts a `mySet` to an `OrderedSet`
    OrderedSet(mySet S) {
        this->elts = S.getelts();
        this->size = S.getsize();
        std::sort(this->elts.begin(), this->elts.end());
    }

    // Ensures set remains sorted
    void SortSet() {
        std::sort(this->elts.begin(), this->elts.end());
    }

    // Adds an element and ensures the set remains sorted
    bool addelt(int x) {
        if (isfound(x)) return false;
        mySet::addelt(x);
        SortSet();
        return true;
    }

    // Overridden INTERSECTION (`*`)
    OrderedSet operator*(OrderedSet &OS) {
        mySet ms = mySet::operator*(OS);
        OrderedSet temp(ms);
        temp.SortSet();
        return temp;
    }

    // Overridden UNION (`+`)
    OrderedSet operator+(OrderedSet &OS) {
        mySet ms = mySet::operator+(OS);
        OrderedSet temp(ms);
        temp.SortSet();
        return temp;
    }

    // **Declare `operator-` as a friend function**
    friend OrderedSet operator-(OrderedSet &left, OrderedSet &right);

    // Friend function for formatted output
    friend ostream& operator<<(ostream &ost, OrderedSet &OS);
};

#endif
