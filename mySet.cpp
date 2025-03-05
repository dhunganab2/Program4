#include "mySet.h"

// Default constructor initializes an empty set
mySet::mySet() : size(0) {}

// Getters
vector<int>& mySet::getelts() { return elts; }
int mySet::getsize() { return size; }

// Setters
void mySet::setelts(const vector<int>& newElts) { elts = newElts; }
void mySet::setsize(int newSize) { size = newSize; }

// Checks if the set is empty
bool mySet::isempty() { return (size == 0); }

// Checks if an element exists in the set
bool mySet::isfound(int x) const {
    return find(elts.begin(), elts.end(), x) != elts.end();
}


// Adds an element only if not already present
bool mySet::addelt(int x) {
    if (isfound(x)) return false;
    elts.push_back(x);
    size++;
    return true;
}

// Deletes an element if found
bool mySet::deleteelt(int x) {
    auto it = find(elts.begin(), elts.end(), x);
    if (it != elts.end()) {
        elts.erase(it);
        size--;
        return true;
    }
    return false;
}

// Returns the UNION of two sets
mySet mySet::operator+(mySet &S) {
    mySet temp = *this;
    for (int e : S.elts) {
        temp.addelt(e);
    }
    return temp;
}

// Returns the INTERSECTION of two sets
mySet mySet::operator*(mySet &S) {
    mySet temp;
    for (int e : this->elts) {
        if (S.isfound(e)) temp.addelt(e);
    }
    return temp;
}

// Checks if two sets are equal (order does not matter)
bool mySet::operator==(mySet &other) {
    if (this->size != other.size) return false;
    for (int e : this->elts) {
        if (!other.isfound(e)) return false;
    }
    return true;
}

// **Difference operator- (elements in left but NOT in right)**
mySet operator-(const mySet &left, const mySet &right) {
    mySet temp;
    for (int e : left.elts) {
        if (!right.isfound(e)) temp.addelt(e);
    }
    return temp;
}

// **Overloaded `<<` operator for formatted output**
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
