#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include "mySet.h"
#include <algorithm>

class OrderedSet : public mySet {
public:
    OrderedSet() = default;

    OrderedSet(mySet S) {
        this->elts = S.getelts();
        this->size = S.getsize();
        std::sort(this->elts.begin(), this->elts.end());
    }

    void SortSet() {
        std::sort(this->elts.begin(), this->elts.end());
    }

    bool addelt(int x) {
        if (isfound(x)) return false;
        mySet::addelt(x);
        SortSet();
        return true;
    }

    OrderedSet operator*(OrderedSet &OS) {
        mySet ms = mySet::operator*(OS);
        OrderedSet temp(ms);
        temp.SortSet();
        return temp;
    }

    OrderedSet operator+(OrderedSet &OS) {
        mySet ms = mySet::operator+(OS);
        OrderedSet temp(ms);
        temp.SortSet();
        return temp;
    }

    friend OrderedSet operator-(OrderedSet &left, OrderedSet &right);
    friend ostream& operator<<(ostream &ost, OrderedSet &OS);
};

#endif
