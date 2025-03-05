
#include "OrderedSet.h"

OrderedSet::OrderedSet() : mySet() {}


OrderedSet::OrderedSet(mySet S) {
    this->elts = S.getelts();
    this->size = S.getsize();
    std::sort(this->elts.begin(), this->elts.end());
}


void OrderedSet::SortSet() {
    std::sort(this->elts.begin(), this->elts.end());
}


bool OrderedSet::addelt(int x) {
    if (isfound(x)) return false;
    mySet::addelt(x);
    SortSet();
    return true;
}


OrderedSet OrderedSet::operator*(OrderedSet &OS) {
    mySet ms = mySet::operator*(OS);
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}


OrderedSet OrderedSet::operator+(OrderedSet &OS) {
    mySet ms = mySet::operator+(OS);
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}

OrderedSet operator-(OrderedSet &left, OrderedSet &right) {
    mySet ms = operator-(static_cast<mySet&>(left), static_cast<mySet&>(right));
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}
