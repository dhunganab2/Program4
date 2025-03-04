#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include "mySet.h"
#include <algorithm>

class OrderedSet : public mySet {
public:
    // Constructors
    OrderedSet() = default;
    OrderedSet(mySet S);

    // Override addelt to maintain order
    bool addelt(int x) override;


    // Overloaded Operators
    OrderedSet operator+(OrderedSet& OS);
    OrderedSet operator*(OrderedSet& OS);
    friend OrderedSet operator-(OrderedSet& left, OrderedSet& right);

    // Overloaded output stream operator
    friend std::ostream& operator<<(std::ostream& ost, OrderedSet& OS);

private:
    void SortSet();
};

#endif
