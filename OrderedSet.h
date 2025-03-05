#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include "mySet.h"

class OrderedSet : public mySet {
public:
    OrderedSet();
    OrderedSet(mySet S);

    bool addelt(int x);
    void SortSet();

    OrderedSet operator*(OrderedSet &OS);
    OrderedSet operator+(OrderedSet &OS);

    friend OrderedSet operator-(OrderedSet &left, OrderedSet &right);
    friend ostream& operator<<(ostream &ost, OrderedSet &OS);
};

#endif
