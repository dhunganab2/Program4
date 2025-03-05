#include "mySet.h"

mySet::mySet() : size(0) {}

vector<int>& mySet::getelts() {
    return elts;
}
int mySet::getsize() {
    return size;
}

void mySet::setelts(const vector<int>& newElts) {
    elts = newElts;
}
void mySet::setsize(int newSize) {
    size = newSize;
}


bool mySet::isempty() {
    return (size == 0);
}

bool mySet::isfound(int x) const {
    return find(elts.begin(), elts.end(), x) != elts.end();
}


bool mySet::addelt(int x) {
    if (isfound(x)) return false;
    elts.push_back(x);
    size++;
    return true;
}


bool mySet::deleteelt(int x) {
    auto it = find(elts.begin(), elts.end(), x);
    if (it != elts.end()) {
        elts.erase(it);
        size--;
        return true;
    }
    return false;
}

mySet mySet::operator+(mySet &S) {
    mySet temp = *this;
    for (int e : S.elts) {
        temp.addelt(e);
    }
    return temp;
}

mySet mySet::operator*(mySet &S) {
    mySet temp;
    for (int e : this->elts) {
        if (S.isfound(e)) temp.addelt(e);
    }
    return temp;
}

bool mySet::operator==(mySet &other) {
    if (this->size != other.size) return false;
    for (int e : this->elts) {
        if (!other.isfound(e)) return false;
    }
    return true;
}

mySet operator-(const mySet &left, const mySet &right) {
    mySet temp;
    for (int e : left.elts) {
        if (!right.isfound(e)) temp.addelt(e);
    }
    return temp;
}

ostream& operator<<(ostream &ost, mySet &S) {
    if (S.isempty()) {
        ost << "Set is EMPTY";
        return ost;
    }
    ost << "{ ";
    int count = 0;
    for (size_t i = 0; i < S.elts.size(); i++) {
        ost << S.elts[i];
        count++;
        if (i != S.elts.size() - 1) {
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
